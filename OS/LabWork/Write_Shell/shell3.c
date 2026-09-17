#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <readline/readline.h>
#define MAX_LINE 1024
#define MAX_ARGS 100
#define MAX_CHARS 1024 
#define FAILURE 1
#define SUCCESS 0
#define MAX_ENV 100
#define MAX_CMDS 20
#define DELIMITER " \" \t\n"
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
/* this is the function to insert into array;
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
 * $ gcc ./shell3.c -lreadline #flag is important 
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

/* split the raw line on the pipe character
 * so that each piece can later be parsed on its own
 * with parse_command.
 * note: this does not touch redirection, that is handled
 * per segment by parse_command.
 * @return no. of commands found
 */
int split_pipes(char *line, char *commands[]) {
	int count = 0;

	char *token = strtok(line, "|");

	while (token != NULL && count < MAX_CMDS) {
		commands[count++] = token;
		token = strtok(NULL, "|");
	}

	return count;
}

/* split commands 
 * into arguments 
 * note: it will not the pipe in the command.
 * @return no. of args
 */
int parse_command(char *line, char *args[], char **input_file,
					char **output_file) {
	int count = 0;

	*input_file = NULL; 
	*output_file = NULL;
	
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

/* runs a single command inside a pipeline.
 * in_fd is the read end this command should use instead of
 * stdin (or -1 if this is the first command and there is none).
 * out_fd is the write end this command should use instead of
 * stdout (or -1 if this is the last command and there is none).
 * input_file/output_file are the < and > redirections found on
 * pipe ends since that is how a real shell behaves.
 * @return the pid of the forked child so the caller can wait on it.
 */
pid_t execute_piped_command(char *args[],
							int argc,
							char *input_file,
							char *output_file,
							int in_fd,
							int out_fd) {
	pid_t pid = fork();

	if (pid < 0) {
		perror("fork");
		return -1;
	}

	if (pid == 0) {
		char *prog = find_executable(args[0]);
		if (prog == NULL) {
			printf("%s: command not found\n", args[0]);
			exit(FAILURE);
		}

		/* close the read end coming from the previous
	 	 * command in the pipeline, unless this segment has
		 * its own < redirection.
	     */		

		if (in_fd != -1) {
			close(STDIN_FILENO);
			if (dup(in_fd) < 0) {
				perror("dup");
				exit(FAILURE);
			}
			close(in_fd);
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

		/* wire up the write end going to the next command in
		 * the pipeline, unless this segment has its own >
		 * redirection.
		 */
		if (out_fd != -1) {
			close(STDOUT_FILENO);
			if (dup(out_fd) < 0) {
				perror("dup");
				exit(FAILURE);
			}
			close(out_fd);
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
				fprintf(stderr, "Too many arguments\n");
				exit(FAILURE);
		}
	}

	return pid;
}

/* handles a full pipeline of 2 or more commands separated by |.
 * it parses every command first so a mistake in a later command
 * is caught before anything is forked.
 * a pipe is opened between every adjacent pair of commands, each
 * command is forked with execute_piped_command, and the parent
 * closes every pipe fd it opened before waiting on all children.
 */
void execute_pipeline(char *commands[], int numCommands) {
	char *cmdArgs[MAX_CMDS][MAX_ARGS];
	int cmdArgc[MAX_CMDS];
	char *cmdInput[MAX_CMDS];
	char *cmdOutput[MAX_CMDS];
	pid_t pids[MAX_CMDS];

	// parse every command up front, bail out if any of them
	// is malformed so we don't fork half a pipeline.
	for (int i = 0; i < numCommands; i++) {
		cmdArgc[i] = parse_command(commands[i], cmdArgs[i],
									&cmdInput[i],
									&cmdOutput[i]);

		if (cmdArgc[i] <= 0) {
			return;
		}
	}

	int in_fd = -1;

	for (int i = 0; i < numCommands; i++) {
		int fd[2] = { -1, -1 };
		int out_fd = -1;

		if (i < numCommands - 1) {
			if (pipe(fd) < 0) {
				perror("pipe");
				return;
			}
			out_fd = fd[1];
		}

		pids[i] = execute_piped_command(cmdArgs[i], cmdArgc[i],
										cmdInput[i], cmdOutput[i],
										in_fd, out_fd);

		// the parent is done with these ends once the child
		if (in_fd != -1) {
			close(in_fd);
		}
		if (out_fd != -1) {
			close(out_fd);
		}

		in_fd = fd[0]; // next command reads from this pipe
	}

	for (int i = 0; i < numCommands; i++) {
		if (pids[i] > 0) {
			waitpid(pids[i], NULL, 0);
		}
	}
}

/* Considerations
 * shell doesn't store it's history.
 *
 * Features
 * it can set PATH variable 
 * the error handling is improved
 * the input redirection exist 
 * for > < 
 * it now supports pipes, both a single pipe and a chain of
 * multiple pipes.
 * */
int main() {
	char *command;
	char *args[MAX_ARGS];
	char *pipeSegments[MAX_CMDS];
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

		// if the line contains a |, treat it as a pipeline and
		if (strchr(command, '|') != NULL) {
			int numCommands = split_pipes(command, pipeSegments);

			if (numCommands < 1) {
				free(command);
				continue;
			}

			execute_pipeline(pipeSegments, numCommands);
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
