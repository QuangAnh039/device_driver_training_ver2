#include <stdio.h>
#include <string.h>
#include "./buffer_over_flow/buffer_over_flow.h"

int main()
{
    char *str = "Chuoi string gay buffer over flow.........................\n";

    printf("Hello world\n");
    cause_over_flow(str, strlen(str));

    return 0;
}