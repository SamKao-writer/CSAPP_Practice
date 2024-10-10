#include <stdio.h>

void show_bytes(unsigned char *start, size_t len);

int main(int argc, char *argv[])
{
    int a = 0xFF;
    show_bytes((unsigned char *) &a, sizeof(int));
    return 0;
}

void show_bytes(unsigned char *start, size_t len)
{
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", *(start + i));
    printf("\n");
}
