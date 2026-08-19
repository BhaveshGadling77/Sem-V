/* A code demonstrating the race problem
*/
#include <stdio.h>
#include <pthread.h>
long c = 0, c1 = 0, c2 = 0, run = 1;
struct spinlock {
	int lock;
};
struct spinlock mylock;

typedef unsigned int uint;

static inline uint xchg(volatile uint *addr, uint newval) { 
  uint result;
  
  // The + in "+m" denotes a read-modify-write operand.
  asm volatile("lock; xchgl %0, %1" :
               "+m" (*addr), "=a" (result) :
               "1" (newval) :
               "cc");
  return result;
}

void spinlock(struct spinlock *lk) {
  __sync_synchronize();
  while(xchg(&lk->lock, 1) != 0)
    ;
}
void spinunlock(struct spinlock *lk) {
  __sync_synchronize();
  asm volatile("movl $0, %0" : "+m" (lk->lock) : );
}
void *thread1(void *arg) {
	while(run == 1) {
		spinlock(&mylock);
		c++;
		spinunlock(&mylock);
		c1++;
	}
}
void *thread2(void *arg) {
	while(run == 1) {
		spinlock(&mylock);
		c++;
		spinunlock(&mylock);
		c2++;
	}
}
int main() {
	pthread_t th1, th2; 
	mylock.lock = 0;
	pthread_create(&th1, NULL, thread1, NULL);
	pthread_create(&th2, NULL, thread2, NULL);
	//fprintf(stdout, "Ending main\n");
	sleep(2);
	run = 0;
	fprintf(stdout, "c = %ld c1+c2 = %ld c1 = %ld c2 = %ld \n", c, c1+c2, c1, c2);
	fflush(stdout);
}
