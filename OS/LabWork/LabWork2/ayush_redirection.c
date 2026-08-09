#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    close(1);   // Close stdout

    open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    printf("Hello World!\n");

    return 0;
}
