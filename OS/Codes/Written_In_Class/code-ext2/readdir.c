#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/fs.h>
//#include <linux/ext2_fs.h>
#include "ext2_fs.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
	int fd = open(argv[1], O_RDONLY); // argv[1] = /tmp/rt
		int offset = 0;
	struct ext2_dir_entry entry;
	read(fd, &entry, sizeof(entry));
	printf("inode no %d, rec_len %d, type %d, name %s\n",
		entry.inode, entry.rec_len, entry.name_len, entry.name);
	offset += entry.rec_len;

	lseek(fd, offset, SEEK_SET);
	read(fd, &entry, sizeof(entry));
	printf("inode no %d, rec_len %d, type %d, name %s\n",
		entry.inode, entry.rec_len, entry.name_len, entry.name);
	offset += entry.rec_len;

	lseek(fd, offset, SEEK_SET);
	read(fd, &entry, sizeof(entry));
	printf("inode no %d, rec_len %d, type %d, name %s\n",
		entry.inode, entry.rec_len, entry.name_len, entry.name);
	offset += entry.rec_len;

	lseek(fd, offset, SEEK_SET);
	read(fd, &entry, sizeof(entry));
	printf("inode no %d, rec_len %d, type %d, name %s\n",
		entry.inode, entry.rec_len, entry.name_len, entry.name);
	offset += entry.rec_len;
	close(fd); 
}
