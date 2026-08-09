#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
/* int to string logic 
 * using handling every test case.
 */
char *inttostring(int x){
	char arr[20];
	int len = 1, check = 0, i = 0, k = 0;
	arr[19] = '\0';
	int rem = 0;
	char *p = (char *)malloc(sizeof(char) * 20);
	
	if (x == 0 || x == -0) {
    	p[0] = '0';
    	return p;
    }
	
	if (x < 0 && x != 0) {
		check = 1;
		p[k++] = '-';
		x = -1 * x;
	}

	for (i = 18; x > 0; i--) {
		rem = x % 10;
		arr[i] = (char)(rem + '0');
		x = x / 10;
		len++;
	}

	if (check != 1)
		i++;
    
	for (int j = k; j < len+ 1; j++) {
    	p[j] = arr[i + j];
    }

	return p;
}
int main() {
	printf("This is will read from fd = 0.\n");
	printf("Enter the Integer value.\n");
	char arr[128];
	int i = 0;
	int num = 0;
	while (i < 128 && read(0, &arr[i], 1) == 1) {
		if (arr[i] == ' ' || arr[i] == '\n' )
			break;
		// write(1,&arr[i], 1); printing the same integer but using write
		num = num * 10 + (arr[i] - '0');
		i++;
	}
	// printf("the Integer we get is: %d\n", num); // printing the int using printf 
	
	// logic to convert number to string 
	
	char *p = inttostring(num);
	write(1, p,strlen(p));
	printf("\n");
	return 0;
}
