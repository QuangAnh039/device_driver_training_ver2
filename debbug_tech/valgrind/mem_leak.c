#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *mem1 = NULL;
    char *mem2 = NULL;

    mem1 = (char *)malloc(sizeof(char) * 4);
    mem2 = (char *)malloc(sizeof(char) * 4);
    
    printf("Checking memory leak using valgrind \n");

    free(mem1);

    return 0;
}