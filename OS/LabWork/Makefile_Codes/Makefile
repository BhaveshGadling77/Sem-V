try: main.o a.o b.o c.o d.o
	gcc a.o b.o c.o d.o main.o -o try

main.o: main.c
	gcc -c main.c

a.o: a.c ab.h
	gcc -c a.c

b.o: b.c ab.h
	gcc -c b.c

c.o: c.c cd.h
	gcc -c c.c

d.o: d.c cd.h
	gcc -c d.c

clean:
	rm *.o try 
