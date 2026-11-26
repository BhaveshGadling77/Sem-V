#ccreate a file

echo "Hello world" >> C

#add a softlink to it.
ln -s C D

#contents of the C
cat D

#delete C 
rm C

#test what are the cotents of D
cat D


# recreate C 
echo "New Contents" >> C

# perform Cat operation on it.

cat D
