#include <assert.h>
#include <stdio.h>

/* Return 1 when x contains an odd number of 1s; 0 otherwise.
 * Assume w = 32.
 */
int odd_ones(unsigned x)
{
    x ^= x >> 1;
    x ^= x >> 2;
    x ^= x >> 4;
    x ^= x >> 8;
    x ^= x >> 16;

    return x & 0x1;
}

int main(int argc, char *argv[])
{
    assert(odd_ones(~0) == 0);
    assert(odd_ones(~0 << 1) == 1);

    return 0;
}