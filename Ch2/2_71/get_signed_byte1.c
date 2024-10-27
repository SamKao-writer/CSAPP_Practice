#include <assert.h>
#include <stdio.h>

/* Declaration of data type where 4 bytes are packed
 * into an unsigned.
 */
typedef unsigned packed_t;

/* Correct version of just using left, right shift and one subtraction */
int xbyte(packed_t word, int bytenum)
{
    int maxnum = 3;
    return (int) word << ((maxnum - bytenum) << 3) >> (maxnum << 3);
}

int main(int argc, char *argv[])
{
    /* Check nonnegative bytes */
    assert(xbyte(0x00112233, 0) == 0x00000033);
    assert(xbyte(0x00112233, 1) == 0x00000022);
    assert(xbyte(0x00112233, 2) == 0x00000011);
    assert(xbyte(0x00112233, 3) == 0x00000000);

    /* Check negative bytes*/
    assert(xbyte(0xAABBCCDD, 0) == 0xFFFFFFDD);
    assert(xbyte(0xAABBCCDD, 1) == 0xFFFFFFCC);
    assert(xbyte(0xAABBCCDD, 2) == 0xFFFFFFBB);
    assert(xbyte(0xAABBCCDD, 3) == 0xFFFFFFAA);

    return 0;
}