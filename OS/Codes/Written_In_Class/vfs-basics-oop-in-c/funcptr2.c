#include <stdio.h>
int read_ext2(float f) {
	return 2;
}
int read_ntfs(float g) {
	return 4;
}
int write_ext2(char f) {
	return 22;
}
int write_ntfs(char g) {
	return 44;
}
typedef struct file_ops {
	int (*read)(float);
	int (*write)(char);
}file_ops;
file_ops ext2_ops = { read_ext2, write_ext2};
file_ops ntfs_ops = { read_ntfs, write_ntfs};
typedef struct inode {
	int inodeno;
	file_ops *fops;
} inode;
int main() {
	int choice;
	inode in;
	scanf("%d", &choice);
	if(choice == 1)
		in.fops = &ext2_ops;
	else if(choice == 2)
		in.fops = &ntfs_ops;
	printf("%d\n", in.fops->read(10.5));
	printf("%d\n", in.fops->write('c'));
	return 0;
}
