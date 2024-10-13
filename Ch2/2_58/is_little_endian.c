#include <stdio.h>

int is_littel_endian(void)
{
    int mask = 0x12345678;
    int *p = &mask;
    return (*(unsigned char *) p == 0x78);
}

int main(int argc, char *argv[])
{
    printf("%d\n", is_littel_endian());
    return 0;
}