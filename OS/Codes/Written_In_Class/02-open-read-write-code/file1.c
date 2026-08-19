#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int fd;
	char arr[16]; 
	int n, i;
	fd = open(argv[1], O_RDONLY);
	printf("fd = %d\n", fd);
	//fd = open("/etc/passwd", O_RDONLY);
	if(fd == -1) {
		printf("open failed\n");
		return 1;
	}
	// asswert: fd is non-negative integer
	n = read(fd, arr, 10);
	for(i = 0; i < n; i++) 
		putchar(arr[i]);
	n = read(fd, arr, 10);
	for(i = 0; i < n; i++) 
		putchar(arr[i]);
	n = read(fd, arr, 10);
	for(i = 0; i < n; i++) 
		putchar(arr[i]);
	while(read(fd, arr, 1)) 
		putchar(arr[0]);
	close(fd);
}
