#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t one, two;
void *thread1(void *arg) {
	printf("Thead1: Taking lock one\n");
	pthread_mutex_lock(&one);
	printf("Thead1: Taken lock one\n");

	printf("Thead1: sleeping\n");
	sleep(3);

	printf("Thead1: Taking lock two\n");
	pthread_mutex_lock(&two);
	printf("Thead1: Taken lock two\n");

	printf("Thead1: done\n");
	return NULL;
}
void *thread2(void *arg) {
	printf("Thead2: Taking lock two\n");
	pthread_mutex_lock(&two);
	printf("Thead2: Taken lock two\n");

	printf("Thead2: sleeping\n");
	sleep(3);

	printf("Thead2: Taking lock one\n");
	pthread_mutex_lock(&one);
	printf("Thead2: Taken lock one\n");

	printf("Thead2: done\n");
	return NULL;
}
int main() {
	pthread_t th1, th2;
	pthread_mutex_init(&one, NULL);
	pthread_mutex_init(&two, NULL);
	pthread_create(&th1, NULL, thread1, NULL);
	pthread_create(&th2, NULL, thread2, NULL);
	printf("Main: Waiting for threads to get over\n");
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	return 0;
}
