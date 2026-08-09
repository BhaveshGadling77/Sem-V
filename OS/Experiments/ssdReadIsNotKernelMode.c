#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int main(void)
{
    int fd = open("largefile.bin", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    char *buf = malloc(1024 * 1024);
    if (!buf) {
        perror("malloc");
        return 1;
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);

    while (read(fd, buf, 1024 * 1024) > 0)
        ;

    gettimeofday(&end, NULL);

    double elapsed =
        (end.tv_sec - start.tv_sec) +
        (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("Elapsed time: %.3f seconds\n", elapsed);

    close(fd);
    free(buf);
    return 0;
}
