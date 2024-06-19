#include <stdio.h>
#include <string.h>

void cause_over_flow(const char *str, int len)
{
    //if we comment the declaration of buffver array,
    //this program will crash because of buffer over flow.
    // char buff[128];
    char data[10];

    memset(data, 0, sizeof(data));

    // write out of bound
    //the data buffer has 10 bytes length but we write a long
    //string to it.
    snprintf(data, len, "%s", str);
    printf("%s\n", data);
}