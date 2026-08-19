#include <stdio.h>
#include <unistd.h>
int main() {
	int pid;
	char cmd[128];
	while(1) {
		printf("prompt>");
		scanf("%s", cmd);
		pid = fork();
		if(pid == 0) {
			execl(cmd, cmd, NULL);
		} else {
			wait(NULL);
		}
	}
}
