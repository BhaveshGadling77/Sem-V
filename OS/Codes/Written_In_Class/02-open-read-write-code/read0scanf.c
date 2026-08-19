#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int fd, n, i;
	char buf[128];

	close(0);
	fd = open(argv[1], O_RDONLY);
	if(fd == -1) {
		perror("open failed");
		return errno;
	}
	scanf("%s", buf);
	printf("%s\n", buf);
	return 0;
}
