#include <stdio.h>

#define SET_BIT(x, pos) (x |= (1 << pos))
#define CLR_BIT(x, pos) (x &= ~(1 << pos))
#define GET_BIT(x, pos) (!!(x & (1 << pos)))

int main(int argc, char *argv[])
{
    unsigned char a = 0xF0;
    unsigned char pos = 3;
    
    // Try to print out the current bit-level representation
    for (int i = (int)(sizeof(unsigned char) << 3) - 1; i >= 0; i--)
        printf("%2d", GET_BIT(a, i));
    printf("\n");

    // Set a bit and print
    SET_BIT(a, pos);
    for (int i = (int)(sizeof(unsigned char) << 3) - 1; i >= 0; i--)
        printf("%2d", GET_BIT(a, i));
    printf("\n");

    // Clear a bit and print
    CLR_BIT(a, pos + 2);
    for (int i = (int)(sizeof(unsigned char) << 3) - 1; i >= 0; i--)
        printf("%2d", GET_BIT(a, i));
    printf("\n");

    return 0;
}