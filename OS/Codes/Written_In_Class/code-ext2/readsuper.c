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
	int fd = open(argv[1], O_RDONLY); // argv[1] = /dev/sdb1 
	int count, i;
	unsigned int block_size;
	struct ext2_super_block sb; 
	struct ext2_group_desc bgdesc[16];
	if(fd == -1) {
		perror("readsuper:");
		exit(errno);
	}
	//printf("size of super block = %lu\n", sizeof(struct ext2_super_block));

	lseek(fd, 1024, SEEK_CUR);
	count = read(fd, &sb, sizeof(struct ext2_super_block));
	printf("Magic: %x\n", sb.s_magic);
	printf("Inodes Count: %d\n", sb.s_inodes_count);

	printf("log block size %d\n", sb.s_log_block_size);		
	block_size = 1 << sb.s_log_block_size; 
	printf("block size %d\n", block_size);		

	//printf("size of BG DESC = %lu\n", sizeof(struct ext2_group_desc));
	lseek(fd, 1024 + 1024, SEEK_SET);
	count = read(fd, &bgdesc, sizeof(struct ext2_group_desc) * 16);
	for(i = 0; i < 16; i++)
	printf("Inode Table: %d\n", bgdesc[i].bg_inode_table); 

	close(fd); 
}
