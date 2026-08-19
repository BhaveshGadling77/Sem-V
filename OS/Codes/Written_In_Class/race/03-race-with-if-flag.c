/* A code demonstrating the race problem
*/
#include <stdio.h>
#include <pthread.h>
long c = 0, c1 = 0, c2 = 0, run = 1;
int flag = 0;
void *thread1(void *arg) {
	while(run == 1) {
		if(flag)
			c++;
		else
			continue;
		c1++;
		flag  = 0;
	}
}
void *thread2(void *arg) {
	while(run == 1) {
		if(!flag)
			c++;
		else 
			continue;
		c2++;
		flag = 1;
	}
}
int main() {
	pthread_t th1, th2, th3; 
	pthread_create(&th1, NULL, thread1, NULL);
	pthread_create(&th3, NULL, thread1, NULL);
	pthread_create(&th2, NULL, thread2, NULL);
	//fprintf(stdout, "Ending main\n");
	sleep(2);
	run = 0;
	fprintf(stdout, "c = %ld c1+c2 = %ld c1 = %ld c2 = %ld \n", c, c1+c2, c1, c2);
	fflush(stdout);
}
