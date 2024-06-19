#include <stdio.h>
#include <stdlib.h>

void foo()
{
    int *p = NULL;
    printf("*p = %d\n", *p);
}
int main()
{
    printf("Core Dumped Demo\n");
    foo();
    return 0;
}