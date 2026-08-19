/* A code demonstrating the race problem
*/
#include <stdio.h>
#include <pthread.h>
long c = 0, c1 = 0, c2 = 0, run = 1;
int flag = 1;
void *thread1(void *arg) {
	while(run == 1) {
		while(flag == 0) // entry section
		;			// entry section
		flag = 0;	 //entry section
		c++;			// criticial section
		flag = 1;	 // exit section
		c1++; 	/// reminder 
	}
}
void *thread2(void *arg) {
	while(run == 1) {
		while(flag == 0)
		;
		flag = 0;
		c++;
		flag = 1;
		c2++;
	}
}
int main() {
	pthread_t th1, th2; 
	pthread_create(&th1, NULL, thread1, NULL);
	pthread_create(&th2, NULL, thread2, NULL);
	//fprintf(stdout, "Ending main\n");
	sleep(2);
	run = 0;
	fprintf(stdout, "c = %ld c1+c2 = %ld c1 = %ld c2 = %ld \n", c, c1+c2, c1, c2);
	fflush(stdout);
}
