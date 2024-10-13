#include <stdio.h>

int main(int argc, char *argv[])
{
    int x = 0x89ABCDEF;
    int y = 0x76543210;
    int result = (x & 0xFF) | (y & ~0xFF);
    printf("%x\n", result);
    return 0;
}