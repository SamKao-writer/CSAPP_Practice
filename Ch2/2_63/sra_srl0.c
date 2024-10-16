#include <stdio.h>
#include <assert.h>

unsigned srl(unsigned x, int k)
{
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;
    /* Determine the width of the mask */
    int offset = (sizeof(int) << 3) - k;
    /* Using ~0 and left shift to become a mask */
    unsigned mask = ~0U << offset;
    /* Using bitwise AND to finish */
    return xsra & ~mask;
}

int sra(int x, int k)
{
    /* Perform shift logically */
    int xsrl = (unsigned) x >> k;
    /* Determine the width of the mask */
    int offset = (sizeof(int) << 3) - k;
    /* Using ~0 and left shift to become a mask */
    int mask = ~0 << offset;
    /* To determine the higher (w-k) should be 1 or 0 */
    int m = 1 << ((sizeof(int) << 3) - 1);
    mask &= !(x & m) - 1;
    /* Using bitwise inclusive OR to finish */
    return xsrl | mask;
}

int main(int argc, char *argv[])
{
    assert(srl(0xFFFF, 8) == 0xFF);
    assert(sra(~0, 8) == ~0);
    return 0;   
}