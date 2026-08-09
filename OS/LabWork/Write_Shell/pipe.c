#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>

int main() {
	char cmd[128], string[16];

	int cpid, pfd[2];

	while (1) {
		printf("prompt>");
		scanf("%s", cmd);
		pipe(pfd);

		cpid = fork();
		if (cpid == 0) {
			close(pfd[0]);
			write(pfd[1], "hello", 6);
			exit(0);
		} else {
			close(pfd[1]);
			read(pfd[0], string, 6);
			printf("Parent read %s\n", string);
			wait(NULL);
		}
	}
	return 0;
}
