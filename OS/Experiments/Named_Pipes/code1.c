#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int fd[2];
    char buffer[100];

    pipe(fd);

    pid_t pid = fork();

    if (pid > 0) {
        // Parent
        close(fd[0]);   // parent does not read

        char msg[] = "Hello from parent";

        write(fd[1], msg, strlen(msg) + 1);

        close(fd[1]);
    }
    else {
        // Child
        //close(fd[1]);   // child does not write

        read(fd[0], buffer, sizeof(buffer));

        printf("Child received: %s\n", buffer);
		read(fd[0], buffer, sizeof(buffer));
		printf("again Child received: %s\n", buffer);

        close(fd[0]);
    }

    return 0;
}
