#include <stdio.h>
#include<unistd.h>
int main() {
    char path[1024];
    printf("To exit the program press ctrl + d\n");
    int err; 
    while(printf("change directory: ") && (err = scanf("%s", path)) == 1)	{
        chdir(path);
        printf("%d\n", err);
        char dirname[1024];
        getcwd(dirname, 128);
        printf("current Working directory: %s\n", dirname);
    }
    printf("\n");
    return 0;
}
