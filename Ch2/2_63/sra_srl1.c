#include <stdio.h>
#include <assert.h>
#include <limits.h>

unsigned srl1(unsigned x, int k)
{
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;
    /* Determine the width of data type */
    unsigned w = sizeof(unsigned) << 3;

    /* Using 2 << (w - k - 1) to replace 1 << (w - k) to prevent indefined behavior */
    unsigned mask = 2 << (w - k - 1);
    
    return (mask - 1) & xsra;
}

unsigned srl0(unsigned x, int k)
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

int sra1(int x, int k)
{
    /* Perform shift logically */
    int xsrl = (unsigned) x >> k;
    /* Determine the width of data type */
    int w = sizeof(int) << 3;

    /* Create mask like srl function */
    int mask = 2 << (w - k - 1);
    mask = ~(mask - 1);

    /* Determine the leftmost k bit is all 1 or all 0 */
    int sign_bit_mask = 1 << (w - k - 1);
    sign_bit_mask &= xsrl;
    sign_bit_mask = !(sign_bit_mask);

    /* Change the mask */
    mask &= sign_bit_mask - 1;

    return xsrl ^ mask;
}

int sra0(int x, int k)
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
    for (int i = INT_MIN; i < INT_MAX; ++i) 
        assert(sra0(i, 4) == sra1(i, 4));

    assert(sra0(INT_MAX, 4) == sra1(INT_MAX, 4));
    
    for (unsigned i = 0; i < UINT_MAX; ++i)
        assert(srl0(i, 4) == srl1(i, 4));
    
    assert(srl0(UINT_MAX, 4) == srl1(UINT_MAX, 4));

    return 0;   
}