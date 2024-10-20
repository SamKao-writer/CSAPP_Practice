#include <assert.h>
#include <limits.h>
#include <stdio.h>

int odd_ones_0(unsigned x)
{
    x ^= x >> 1;
    x ^= x >> 2;
    x ^= x >> 4;
    x ^= x >> 8;
    x ^= x >> 16;

    return x & 0x1;
}

int odd_ones_1(unsigned x)
{
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;

    return x & 0x1;
}

int main(int argc, char *argv[])
{
    for (unsigned i = 0; i < UINT_MAX; ++i)
        assert(odd_ones_0(i) == odd_ones_1(i));
    assert(odd_ones_0(UINT_MAX) == odd_ones_1(UINT_MAX));

    return 0;
}