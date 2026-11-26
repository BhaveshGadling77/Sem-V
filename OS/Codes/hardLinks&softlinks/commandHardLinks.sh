#create a file 
touch A 

# Add contents to it
echo "Hello this orignal File" >> A

# create a hardlink
ln A B

# try deleting the A
rm A

# cat the contents of B
cat B

