#include<stdio.h>
typedef struct semaphore {
	condition c;

} semaphore;

P(semaphore *s) {
	--p;
	while(p < 0)
		;
}

V(semaphore *s) {
	++p;
}
