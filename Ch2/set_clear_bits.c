#include <stdio.h>

#define SET_BIT(x, pos) (x |= (1 << pos))
#define CLR_BIT(x, pos) (x &= ~(1 << pos))
#define TOG_BIT(x, pos) (x ^= (1 << pos))
#define GET_BIT(x, pos) (!!(x & (1 << pos)))

#define PRINT(type, a)                                       \
    for (int i = (int) (sizeof(type) << 3) - 1; i >= 0; i--) \
        printf("%2d", GET_BIT(a, i));                        \
    printf("\n")

int main(int argc, char *argv[])
{
    unsigned char a = 0xF0;
    unsigned char pos = 3;

    // Try to print out the current bit-level representation
    PRINT(unsigned char, a);

    // Set a bit and print
    SET_BIT(a, pos);
    PRINT(unsigned char, a);

    // Clear a bit and print
    CLR_BIT(a, pos + 2);
    PRINT(unsigned char, a);

    // Toggle a bit and print
    TOG_BIT(a, pos);
    PRINT(unsigned char, a);

    return 0;
}