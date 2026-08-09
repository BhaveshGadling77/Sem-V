#include<stdio.h>
#include<stdbool.h>

bool solve(int n) {
	if (n % 4 == 0 && n % 100 != 0) {
		return true;
	} else if (n % 400 == 0)
		return true;
	
	return false;
}
int main() {
	int n;
	printf("Enter the number: ");
	scanf("%d", &n);
	printf("this is ans: %b", solve(n));
}
