#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <readline/history.h>
#define MAX_LINE 1024
#define MAX_ARGS 100
#define MAX_CHARS 1024 
#define FAILURE 1
#define SUCCESS 0
#define ENV INT_MAX
#define NOT_FOUND NULL 
#define MAX_ENV 100
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
 * 
 * @return ENV;
 */
int parse_command(char *line, char *args[],
                  char **inputFile,
                  char **outputFile) {
    int count = 0;

    *inputFile = NULL;
    *outputFile = NULL;

    char *token = strtok(line, " \t\n");

    while (token != NULL) {
        if (strcmp(token, "<") == 0) {
            token = strtok(NULL, " \t\n");

            if (token == NULL) {
                fprintf(stderr,
                        "Missing input file\n");

                return -1;
            }

            *inputFile = token;
        }
        else if (strcmp(token, ">") == 0) {
            token = strtok(NULL, " \t\n");

            if (token == NULL) {
                fprintf(stderr,
                        "Missing output file\n");

                return -1;
            }

            *outputFile = token;
        }
        else {
            args[count++] = token;
        }

        token = strtok(NULL, " \t\n");
    }
    args[count] = NULL;

    return count;
}

/* Find executable
 */

char *findExecutable(char *cmd) {
	static char fullPath[PATH_MAX];

	if (strchr(cmd, '/'))
	{
		if (stat(cmd, &(struct stat){0}) == 0)
			return cmd;

		return NULL;
	}

	char *path = getEnvValue("PATH");

	if (path == NULL)
		return NULL;

	char temp[1024];

	strcpy(temp, path);

	char *dir = strtok(temp, ":");

	while (dir) {
		snprintf(fullPath,
				 sizeof(fullPath),
				 "%s/%s",
				 dir,
				 cmd);

		struct stat st;
		if (stat(fullPath, &st) == 0 && S_ISREG(st.st_mode))
		    return fullPath;

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
                     char *inputFile,
                     char *outputFile) {

	pid_t pid = fork();

	if (pid < 0) {
		perror("fork");
		return;
	}

	if (pid == 0) {
		char *program = findExecutable(args[0]);
		if (program == NULL) {
		    fprintf(stderr, "%s: command not found\n", args[0]);
		    exit(FAILURE);
		}
		if (inputFile != NULL) {
		    int fd = open(inputFile, O_RDONLY);

		    if (fd < 0) {
				perror(inputFile);
				exit(FAILURE);
		    }

		    if (dup2(fd, STDIN_FILENO) < 0) {
				perror("dup2");
				close(fd);
				exit(FAILURE);
		    }

		    close(fd);
		}
		if (outputFile != NULL) {
		    int fd = open(outputFile,
				  O_WRONLY | O_CREAT | O_TRUNC,
				  0644);

		    if (fd < 0) {
				perror(outputFile);
				exit(FAILURE);
		    }

		    if (dup2(fd, STDOUT_FILENO) < 0) {
				perror("dup2");
				close(fd);
				exit(FAILURE);
		    }

		    close(fd);
		}
		switch (argc) {
		case 1:
		    execl(program,
			  args[0],
			  NULL);
		    break;

		case 2:
		    execl(program,
			  args[0],
			  args[1],
			  NULL);
		    break;

		case 3:
		    execl(program,
			  args[0],
			  args[1],
			  args[2],
			  NULL);
		    break;

		case 4:
		    execl(program,
			  args[0],
			  args[1],
			  args[2],
			  args[3],
			  NULL);
		    break;

		default:
		    fprintf(stderr,
			    "Too many arguments\n");
		}

		perror("execl");
		exit(FAILURE);
	}
	wait(NULL);
}

/* Considerations
 * shell doesn't store it's history.
 * shell doesn't allow you to pipe commands
 * Till now.
 * 
 * Features
 * it should has the setting env variables.
 * it should be able to able to set the PATH variable 
 * the error handling should be able to command. 
 */
int main() {
	char *command;
	char *args[MAX_ARGS];
	char *inputFile;
	char *outputFile;
	setEnvValue("PATH", "/usr/bin:/bin");
	while (1) {
		command = read_command();

		char *equal = strchr(command,'=');

		if (equal) {
		    *equal = '\0';
		    setEnvValue(command,equal+1);

		    free(command);
		    continue;
		}

		if (command == NULL)
			break;
		int argc = parse_command(command,
                         args,
                         &inputFile,
                         &outputFile);
		if (argc == 0) {
			printf("\nGoodbye!\n");
			free(command);
			continue;
		}
		if (argc == -1) {
		    free(command);
		    continue;
		}
		
		if (builtin_command(args)) {
			free(command);
			continue;
		}

		execute_command(args,
                argc,
                inputFile,
                outputFile);
                free(command);
	}
	return 0;
}
