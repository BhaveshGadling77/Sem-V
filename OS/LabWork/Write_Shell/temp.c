#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#define MAX_LINE 1024
#define MAX_ARGS 100
#define MAX_CHARS 1024 
#define FAILURE 1
#define SUCCESS 0
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
 */
int parse_command(char *line, char *args[]) {
	int count = 0;
	char *token = strtok(line, " \t\n");

	while (token != NULL) {
		args[count++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[count] = NULL;

	return count;
}

/* handles built-in commands */
int builtin_command(char *args[])
{
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
void execute_command(char *args[]) {

	pid_t pid = fork();

	if (pid < 0) {
		perror("fork");
		return;
	}

	if (pid == 0) {
		execvp(args[0], args);
		perror("execvp");
		exit(FAILURE);
	}
	wait(NULL);
}

/* Considerations
 * shell doesn't store it's history.
 * shell doesn't allow you to pipe commands
 * */
int main() {
	char *command;
	char *args[MAX_ARGS];

	while (1) {
		command = read_command();
		if (command == NULL)
        	break;

		int argc = parse_command(command, args);

		if (argc == 0) {
			printf("\nGoodbye!\n");
			free(command);
			continue;
		}

		if (builtin_command(args)) {
			free(command);
			continue;
		}

		execute_command(args);
	}
	return 0;
}
