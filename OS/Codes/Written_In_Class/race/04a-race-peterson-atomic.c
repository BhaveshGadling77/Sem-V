/* A code demonstrating the race problem
*/
#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>
#include <unistd.h>
#define TRUE 1
#define FALSE 0
atomic_long c = 0, c1 = 0, c2 = 0, run = 1;
atomic_int flag[3] = {-1, FALSE, FALSE};
atomic_int turn = 1;
void *thread1(void *arg) {
    while(run == 1) {
        atomic_store(&flag[1], TRUE);
        atomic_store(&turn, 2);
        while(atomic_load(&flag[2]) == TRUE && atomic_load(&turn) == 2)
            ;

        atomic_fetch_add(&c, 1);

        atomic_store(&flag[1], FALSE);
        c1++;
    }
    return NULL;
}
/*
void *thread1(void *arg) {
	while(run == 1) {
		flag[1] = TRUE;
		turn = 2;
		while(flag[2] == TRUE && turn == 2)
			;

		c++;

		flag[1] = FALSE;
		c1++;
	}
	return NULL;
}
*/
void *thread2(void *arg) {
    while(run == 1) {
        atomic_store(&flag[2], TRUE);
        atomic_store(&turn, 1);
        while(atomic_load(&flag[1]) == TRUE && atomic_load(&turn) == 1)
            ;

        atomic_fetch_add(&c, 1);

        atomic_store(&flag[2], FALSE);
        c1++;
    }
    return NULL;
}
/*
void *thread2(void *arg) {
	while(run == 1) {
		flag[2] = TRUE;
		turn = 1;
		while(flag[1] == TRUE && turn == 1)
			;

		c++;

		flag[2] = FALSE;
		c2++;
	}
	return NULL;
}
*/
int main() {
	pthread_t th1, th2; 
	pthread_create(&th1, NULL, thread1, NULL);
	pthread_create(&th2, NULL, thread2, NULL);
	//fprintf(stdout, "Ending main\n");
	sleep(2);
	run = 0;
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	fprintf(stdout, "c = %ld c1+c2 = %ld c1 = %ld c2 = %ld \n", c, c1+c2, c1, c2);
	fflush(stdout);
}
