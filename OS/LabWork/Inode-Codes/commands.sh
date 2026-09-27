#create a folder to test
mkdir -p ./mount-demo/test

#create a file inside that folder
echo "I belong to original folder" >> ./mount-demo/test/original.txt

#create a file (which we will use as filesystem)
dd if=/dev/zero of=./disk.img bs=1M count=50 #this creates a file of size 50MB

#format the empty filesystem
mkfs.ext4 ./disk.img

#mount to the directory
sudo mount -o loop ./disk.img ./mount-demo/test

#check the partition it might show you lost+found/ folder or empty directory
ls ./mount-demo/test

#create the file in this file system
echo "I belong to mounted file system" >> ./mount-demo/test/mounted.txt


