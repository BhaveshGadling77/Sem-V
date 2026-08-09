#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <readline/readline.h>
#include <readline/history.h>
#define MAX_LINE 1024
#define MAX_ARGS 100
#define MAX_CHARS 1024 
#define FAILURE 1
#define SUCCESS 0
#define MAX_ENV 100
#define DELIMITER " \t\n"
// struct for env_variables.
typedef struct env_var {
    char key[64];
    char value[1024];
} env_var;

env_var envs[MAX_ENV];

int envCount = 0;
/* this function is need to find the given value of env variable. 
 * it is intended to 
 * return value(if it exist);
 * otherwise
 * return NOT_FOUND;
 */ 
char *getEnvValue(const char *key) {
	for (int i = 0; i < envCount; i++) {
		if (strcmp(envs[i].key, key) == 0)
			return envs[i].value;
	}

	return NULL;
}
/* This is the function to insert into array;
 * it expects a struct of env_var, and array of env_var 
 * on success it return size of current array;
 * on failure it return -1;
 * caller has to care of free.
 */
void setEnvValue(const char *key, const char *value) {
	for (int i = 0; i < envCount; i++) {
		if (strcmp(envs[i].key, key) == 0) {
			strcpy(envs[i].value, value);
			return;
		}
	}

	strcpy(envs[envCount].key, key);
	strcpy(envs[envCount].value, value);
	envCount++;
}
/* Readline is external library function you have to install it 
 * $ sudo apt-get install libreadline-dev 
 * $ gcc ./shell1.c -lreadline #flag is important 
 */
/* reads one line of input
 * this function will return malloced array pointer.
 * note: caller has to take care of memory allocated.
 */
char* read_command() {
	char cwd[MAX_CHARS];
	getcwd(cwd, MAX_CHARS);
	strcat(cwd, "> ");
	return readline(cwd);
}

/* split commands 
 * into arguments 
 * note: it will not the pipe in the command.
 * @return no. of args
 */
int parse_command(char *line, char *args[], char **input_file,
					char **output_file) {
	int count = 0;

	*input_file = NULL; //considering that there is no inputfile
	*output_file = NULL; //considering that there is no output file.
	
	char *token = strtok(line, DELIMITER);
	
	while (token != NULL) {
		if (strcmp(token, ">") == 0) {
			token = strtok(NULL, DELIMITER);
			if (token == NULL) {
				printf("Missing output file.\n");
				return -1;
			}

			*output_file = token;
		} else if (strcmp(token, "<") == 0) {
			token = strtok(NULL, DELIMITER);

			if (token == NULL) {
				printf("Missing input file.\n");
				return -1;
			}

			*input_file = token;
		} else {
			args[count++] = token;
		} 
		
		token = strtok(NULL, DELIMITER);
	}
	args[count] = NULL;

	return count;
}
// find executeble according to the current value of PATH Variable 
char *find_executable(char *cmd) {
	static char fullPATH[PATH_MAX];
	struct stat st;
	
	//if the user already given path to executable 
	//resolve using syscall to kernel
	if (strchr(cmd, '/')) {
		if (stat(cmd, &st) != 0) 
			return NULL;

		return cmd;
	}
	// if path is not given 
	
	char *path = getEnvValue("PATH");

	if (path == NULL)
		return NULL;

	char temp[1024];
	strcpy(temp, path);

	char *dir = strtok(temp, ":");

	while (dir) {
		snprintf(fullPATH,
				sizeof(fullPATH),
				"%s/%s",
				dir,
				cmd);
		if (stat(fullPATH, &st) == 0 && S_ISREG(st.st_mode)) {
			return fullPATH;
		}

		dir = strtok(NULL, ":");
	}

	return NULL;
}

/* handles built-in commands */
int builtin_command(char *args[]) {
	if (args[0] == NULL)
		return 1;

	// exit command
	if (strcmp(args[0], "exit") == 0) {
		printf("Goodbye!\n");
		exit(SUCCESS);
	}

	// cd command 
	if (strcmp(args[0], "cd") == 0) {
		if (args[1] == NULL) {
			fprintf(stderr, "cd: missing operand\n");
		}
		else if (chdir(args[1]) != 0) {
			perror("cd");
		}
		return 1;
	}
	return 0;
}

// for commands other than cd and exit 
void execute_command(char *args[],
						int argc,
						char *input_file,
						char *output_file) {

	pid_t pid = fork();

	if (pid < 0) {
		perror("fork");
		return;
	}

	if (pid == 0) {
		char *prog = find_executable(args[0]);
		if (prog == NULL) {
			printf("%s: command not found\n", args[0]);
			exit(FAILURE);
		}
		if (input_file != NULL) {
			int fd = open(input_file, O_RDONLY);
			if (fd < 0) {
				perror(input_file);
				exit(FAILURE);
			}

			close(STDIN_FILENO);

			if (dup(fd) < 0) {
				perror("dup");
    			close(fd);
    			exit(FAILURE);
			}
			close(fd);
		}
		if (output_file != NULL) {
			int fd = open(output_file,
							O_WRONLY | O_CREAT | O_TRUNC,
							0644);
			if (fd < 0) {
				perror(output_file);
				exit(FAILURE);
			}

			close(STDOUT_FILENO);
			if (dup(fd) < 0) {
				perror("dup");
				close(fd);
				exit(FAILURE);
			}

			close(fd);
		}

		switch (argc) {
			case 1:
				execl(prog, args[0], NULL);
				break;

			case 2:
				execl(prog, args[0], args[1], NULL);
				break;
		
			case 3:
				execl(prog, args[0],
						args[1],
						args[2],
						NULL);
				break;
			case 4:
				execl(prog,
					args[0],
					args[1],
					args[2],
					args[3],
					NULL);
				break;

			default:
				fprintf(stderr,"Too many arguments\n");
		}
	}
	wait(NULL);
}

/* Considerations
 * shell doesn't store it's history.
 * shell doesn't allow you to pipe commands
 *
 * Features
 * it can set PATH variable 
 * the error handling is improved
 * the input redirection exist 
 * for > < 
 * */
int main() {
	char *command;
	char *args[MAX_ARGS];
	char *input_file;
	char *output_file;
	setEnvValue("PATH", "/usr/bin:/bin");

	while (1) {
		command = read_command();
		if (command == NULL) {
			printf("Goodbye!\n");
			break;
		}


		char *equal = strchr(command, '=');

		if (equal) {
			*equal = '\0';
			setEnvValue(command, equal+1);// as there is only one environment variable.

			free(command);
			continue;
		}
		int argc = parse_command(command, args,
									&input_file,
									&output_file);


		if (argc == 0) {
			printf("\nGoodbye!\n");
			free(command);
			continue;
		}

		if (builtin_command(args)) {
			free(command);
			continue;
		}

		execute_command(args, argc,
					input_file,
					output_file);
		free(command);
	}
	return 0;
}
