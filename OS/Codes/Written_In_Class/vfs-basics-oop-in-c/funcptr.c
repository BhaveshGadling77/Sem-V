#include <stdio.h>
void h() {	
	printf("in f\n");
	return;
}
int f(int a) {
	return a + 5;
}
int g(int b) {
	return b + 10;
}
// signature 
// int (int, float, char *);
//int (*g)(int b);
int main() {
	int (*func) (int);
	void (*hp) ();
	int choice;
	hp =&h;
	h();
	scanf("%d", &choice);
	if(choice == 1)
		func = f;
	else if(choice == 2)
		func = g;
	printf("%d\n", func(10));
	return 0;
}
