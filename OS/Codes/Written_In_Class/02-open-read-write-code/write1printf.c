#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int fd, n, i;
	char buf[128];

	close(1);
	fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if(fd == -1) {
		perror("open failed");
		return errno;
	}
	printf("abhijit\n");
	return 0;
}
