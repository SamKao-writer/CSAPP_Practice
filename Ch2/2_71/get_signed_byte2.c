#include <assert.h>
#include <limits.h>
#include <stdio.h>

typedef unsigned packed_t;

int xbyte_r(packed_t word, int bytenum)
{
    return (char) (word >> (bytenum << 3));
}

int xbyte(packed_t word, int bytenum)
{
    int maxnum = 3;
    return (int) word << ((maxnum - bytenum) << 3) >> (maxnum << 3);
}

int main(int argc, char *argv[])
{
    /* Check nonnegative bytes */
    assert(xbyte_r(0x00112233, 0) == 0x00000033);
    assert(xbyte_r(0x00112233, 1) == 0x00000022);
    assert(xbyte_r(0x00112233, 2) == 0x00000011);
    assert(xbyte_r(0x00112233, 3) == 0x00000000);

    /* Check negative bytes*/
    assert(xbyte_r(0xAABBCCDD, 0) == 0xFFFFFFDD);
    assert(xbyte_r(0xAABBCCDD, 1) == 0xFFFFFFCC);
    assert(xbyte_r(0xAABBCCDD, 2) == 0xFFFFFFBB);
    assert(xbyte_r(0xAABBCCDD, 3) == 0xFFFFFFAA);

    /* Comapre these two version in different test cases */
    for (unsigned i = 0; i < UINT_MAX; ++i)
        for (int j = 0; j < 4; ++j)
            assert(xbyte_r(i, j) == xbyte(i, j));

    for (int j = 0; j < 4; ++j)
        assert(xbyte_r(UINT_MAX, j) == xbyte(UINT_MAX, j));

    return 0;
}