#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int fd, n, i;
	char buf[128];

	n = read(0, buf, 5);
	buf[5] = '\0';
	printf("%s\n", buf); /*
	for(i = 0; i < n; i++)
		putchar(buf[i]);	
	return 0; */
}
