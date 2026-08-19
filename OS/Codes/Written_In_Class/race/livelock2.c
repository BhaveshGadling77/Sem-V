#include <stdio.h>
#include <pthread.h>
struct person {
	int otherid;
	int otherHungry;
	int myid;
};
/* thread two runs in this function */
int spoonWith = 1;
void *eat(void *param)
{
  int eaten = 0;
  struct person person= *(struct person *)param;
  while (!eaten) {
		if(spoonWith == person.myid)
			printf("%d going to eat\n", person.myid);
		else
			continue;
		if(person.otherHungry) {
			printf("You eat %d\n", person.otherid);
			spoonWith = person.otherid;
			continue;
		}
		printf("%d is eating\n", person.myid);
		break;		
  }
}
int main() {
	pthread_t th1, th2;
	struct person one, two;	
	one.otherid = 2; one.myid = 1;
	two.otherid = 1; two.myid = 2;
	one.otherHungry = two.otherHungry = 1;
	pthread_create(&th1, NULL, eat, &one);
	pthread_create(&th2, NULL, eat, &two);
	printf("Main: Waiting for threads to get over\n");
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	return 0;
}
