#include <assert.h>
#include <stdio.h>

/*
 * Mask with least significant n bits set to 1
 * Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
 * Assume 1 <= n <= w
 */
int lower_one_mask(int n)
{
    int w = (int) (sizeof(int) << 3);
    return ~0U >> (w - n);
}

int main(int argc, char *argv[])
{
    assert(lower_one_mask(6) == 0x3F);
    assert(lower_one_mask(17) == 0x1FFFF);

    return 0;
}