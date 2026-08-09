#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
int main() {
	close(1);
	int fd = open("output.t", O_WRONLY | O_CREAT, 0644);

	printf("Hello World!.\n");
}
