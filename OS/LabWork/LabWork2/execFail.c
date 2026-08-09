#include<stdio.h>
#include<unistd.h>
#include<errno.h>
int main () {
	int pid = fork();
	if (pid == 0) {
		// E
		printf("Child Process created...\n");
		execl("/bin/cattt", "cat", "./some.txt", NULL);
        perror("execl");
        printf("errno = %d\n", errno);
		
		// ENOEXEC
		// to create this execute $ echo "This is not a executable file." >> testfile && chmod a+x testfile 

		printf("Child process is executing the testfile.\n");
		execl("./testfile", "testfile", "./some.txt", NULL);
		perror("execl");
		printf("errno = %d\n", errno);
	}
	else {
		printf("Parent process exited.\n");
	}


}
