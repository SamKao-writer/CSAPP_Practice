#include <assert.h>
#include <limits.h>
#include <stdio.h>

int leftmost_one0(unsigned x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return x ^ (x >> 1);
}

int leftmost_one1(unsigned x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return x & (~x >> 1);
}

int main(int argc, char *argv[])
{
    // for (unsigned i = 0; i < UINT_MAX; ++i)
    //     assert(leftmost_one0(i) == leftmost_one1(i));
    printf("0x");
    printf("%.8x\n", leftmost_one1(UINT_MAX));
    return 0;
}
