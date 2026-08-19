a.out: a.o main.o
	cc a.o main.o -o a.out
	objdump -x -D  a.out > dumpaout
	echo "Read the files: dumpao dumpmaino dumpaout"
a.o: a.c 
	cc -S a.c
	as a.s -o a.o
	objdump -x -D a.o > dumpao
main.o: main.c
	cc -S main.c
	as main.s -o main.o
	objdump -x -D main.o > dumpmaino
