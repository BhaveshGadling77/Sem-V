/*
 * Commands used for creating:
 *
 * $dd if=/dev/zero of=/tmp/myfile bs=1M count=100
 * $mkfs.ext2 /tmp/myfile
 *
 * $sudo mkdir -p ./mount-demo/ext2
 * $sudo mount -o loop /tmp/myfile ./mount-demo/ext2
 * after compilation on my system (ubuntu 26.04 LTS) if use inode-number 
 * 11 then i can see the some output other than 0.(which is again a lost+found/ )
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <inttypes.h>
#include <ext2fs/ext2_fs.h>

/*
 * Read data from the filesystem at the given byte offset.
 */
int read_at(int fd, void *buffer, size_t size, off_t offset) {
	ssize_t bytes_read;

	if (lseek(fd, offset, SEEK_SET) == (off_t)-1) {
		perror("lseek64");
		return -1;
	}

	bytes_read = read(fd, buffer, size);

	if (bytes_read != (ssize_t)size) {
		if (bytes_read < 0) {
			perror("read");
		} else {
			fprintf(stderr, "Could not read enough data\n");
		}

		return -1;
	}

	return 0;
}


/*
 * convert the inode number given on the command line into an integer.
 * as sir unable enter normal 10 instead of /10.
 */
int parse_inode_number(const char *argument) {
	char *end;
	unsigned long value;

	if (argument[0] == '/') {
		argument++;
	}

	value = strtoul(argument, &end, 10);

	if (*end != '\0' || value == 0 || value > INT_MAX) {
		fprintf(stderr, "Invalid inode number: %s\n", argument);
		exit(EXIT_FAILURE);
	}

	return (int)value;
}


/*
 * print the inode struct.
 */
void print_inode(struct ext2_inode *inode) {
	uint i;

	printf("Inode\n");
	printf("\n");

	printf("Mode			 : 0x%04x\n",
		   inode->i_mode);

	printf("UID			     : %u\n",
		   inode->i_uid);

	printf("Size			 : %u\n",
		   inode->i_size);

	printf("Access time	     : %u\n",
		   inode->i_atime);

	printf("Creation time	 : %u\n",
		   inode->i_ctime);

	printf("Modification time: %u\n",
		   inode->i_mtime);

	printf("Deletion time	 : %u\n",
		   inode->i_dtime);

	printf("GID			     : %u\n",
		   inode->i_gid);

	printf("Links count	     : %u\n",
		   inode->i_links_count);

	printf("Blocks			 : %u\n",
		   inode->i_blocks);

	printf("Flags			 : 0x%08x\n",
		   inode->i_flags);

	printf("File ACL		 : %u\n",
		   inode->i_file_acl);

	printf("Directory ACL	 : %u\n",
		   inode->i_file_acl);

	printf("Fragment address : %u\n",
		   inode->i_faddr);

	printf("\nBlock pointers\n\n");

	for (i = 0; i < EXT2_N_BLOCKS; i++) {
		printf("i_block[%2d]	   : %u\n",
			   i,
			   inode->i_block[i]);
	}
}


/*
 * Read the superblock, group descriptor and requested inode.
 */
int main(int argc, char *argv[]) {
	int fd;

	struct ext2_super_block super;
	struct ext2_group_desc group_desc;
	struct ext2_inode inode;

	uint inode_number;
	uint group_number;
	uint inode_index;

	uint block_size;
	uint inodes_per_group;
	uint inode_size;

	uint inode_table_block;

	off_t group_desc_offset;
	off_t inode_table_offset;
	off_t inode_offset;

	if (argc != 3) {
		fprintf(stderr,
				"Usage: %s <filesystem-file> <inode-number>\n",
				argv[0]);

		return EXIT_FAILURE;
	}

	inode_number = parse_inode_number(argv[2]);

	fd = open(argv[1], O_RDONLY);

	if (fd == -1) {
		perror("open");
		return EXIT_FAILURE;
	}

	if (read_at(fd, &super,
				sizeof(struct ext2_super_block),
				1024) == -1) {
		close(fd);
		return EXIT_FAILURE;
	}

	if (super.s_magic != EXT2_SUPER_MAGIC) {
		fprintf(stderr,
				"The file does not contain an ext2 filesystem\n");

		close(fd);
		return EXIT_FAILURE;
	}

	block_size = 1024U << super.s_log_block_size;

	inodes_per_group = super.s_inodes_per_group;
	inode_size = super.s_inode_size;

	if (inode_size == 0) {
		inode_size = EXT2_GOOD_OLD_INODE_SIZE;
	}

	if (inode_number > super.s_inodes_count) {
		fprintf(stderr,
				"Invalid inode number. Maximum inode number is %u\n",
				super.s_inodes_count);

		close(fd);
		return EXIT_FAILURE;
	}

	group_number = (inode_number - 1) / inodes_per_group;

	inode_index = (inode_number - 1) % inodes_per_group;

	if (block_size == 1024) {
		group_desc_offset = 2 * (off_t)block_size;
	} else {
		group_desc_offset = 1 * (off_t)block_size;
	}

	group_desc_offset += group_number * sizeof(struct ext2_group_desc);

	if (read_at(fd,
				&group_desc,
				sizeof(struct ext2_group_desc),
				group_desc_offset) == -1) {
		close(fd);
		return EXIT_FAILURE;
	}

	inode_table_block = group_desc.bg_inode_table;

	inode_table_offset =
		(off_t)inode_table_block * block_size;

	inode_offset =
		inode_table_offset +
		(off_t)inode_index * inode_size;

	memset(&inode, 0, sizeof(inode));

	if (inode_size < sizeof(struct ext2_inode)) {
		if (read_at(fd, &inode, inode_size, inode_offset) == -1) {
			close(fd);
			return EXIT_FAILURE;
		}
	} else {
		if (read_at(fd,
					&inode,
					sizeof(struct ext2_inode),
					inode_offset) == -1) {
			close(fd);
			return EXIT_FAILURE;
		}
	}

	printf("Filesystem		: %s\n", argv[1]);
	printf("Inode number	  : %u\n", inode_number);
	printf("Block size		: %u\n", block_size);
	printf("Inode size		: %u\n", inode_size);
	printf("Block group	   : %u\n", group_number);
	printf("Inode index	   : %u\n", inode_index);
	printf("Inode table block : %u\n", inode_table_block);
	printf("Inode offset	  : %" PRIu64 "\n",
		   (uint64_t)inode_offset);

	printf("\n");

	print_inode(&inode);

	close(fd);

	return EXIT_SUCCESS;
}
