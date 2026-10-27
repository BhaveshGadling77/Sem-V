#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        // CHILD
        char buf[100];

        while (read(fd[0], buf, sizeof(buf)) > 0) {
            printf("Child got: %s\n", buf);
        }

        printf("Child: EOF received\n");
    }
    else {
        // PARENT
        char msg[] = "Hello";

        write(fd[1], msg, strlen(msg) + 1);

        printf("Parent: finished writing\n");

        wait(NULL);
    }

    return 0;
}
