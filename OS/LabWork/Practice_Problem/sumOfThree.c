#include<stdio.h>

int main() {
	int x, y, z;

	printf("Enter Three Numbers: ");
	scanf("%d %d %d", &x, &y, &z);

	int sum = x + y + z;

	printf("Sum: %d\n", sum);
}
