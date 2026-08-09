#!/bin/bash 
echo "This program will create 1000 files of a particular extension";
echo "Which files you want to create: ";
read ext;

for i in {1..1000};
do
	touch file$i.$ext;
done
