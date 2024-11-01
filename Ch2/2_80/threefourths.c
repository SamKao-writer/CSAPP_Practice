#include <assert.h>
#include <limits.h>
#include <stdio.h>

int threefourths(int x)
{
    int sign_mask = INT_MIN;
    int is_neg = x & sign_mask;

    int q = x & ~0x3;
    int r = x & 0x3;

    q = q >> 2;
    q = (q << 1) + q;

    r = (r << 1) + r;
    is_neg && (r = r + ((1 << 2) - 1));
    r = r >> 2;

    return q + r;
}

int main(int argc, char *argv[])
{
    assert(threefourths(8) == 6);
    assert(threefourths(9) == 6);
    assert(threefourths(10) == 7);
    assert(threefourths(11) == 8);
    assert(threefourths(12) == 9);

    assert(threefourths(-8) == -6);
    assert(threefourths(-9) == -6);
    assert(threefourths(-10) == -7);
    assert(threefourths(-11) == -8);
    assert(threefourths(-12) == -9);
    
    return 0;
}