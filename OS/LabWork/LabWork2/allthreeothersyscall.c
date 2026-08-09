#include<unistd.h>
#include<sys/wait.h>
int main() {
	
	//same command
	int pid = fork();
	if (pid == 0)
		execl("/bin/ls", "ls", "-la", NULL);
	wait(NULL);	
	//same command 
	pid = fork();
	if (pid == 0)
		execlp("ls", "ls", "-la", NULL);
	wait(NULL);
	
	// same command 
	char *args[] = {"ls", "-la", NULL};
	pid = fork();
	if (pid == 0)
		execvp("ls", args);
	wait(NULL);
	return 0;
}
