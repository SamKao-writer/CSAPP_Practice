#include <assert.h>
#include <limits.h>
#include <stdio.h>

unsigned srl1(unsigned x, int k)
{
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;
    /* Determine the width of data type */
    unsigned w = sizeof(unsigned) << 3;

    /* Using 2 << (w - k - 1) to replace 1 << (w - k) to prevent indefined
     * behavior */
    unsigned mask = 2 << (w - k - 1);

    return (mask - 1) & xsra;
}

unsigned srl2(unsigned x, int k)
{
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;
    /* Determine the width of data type */
    unsigned w = sizeof(unsigned) << 3;

    /* Determine m */
    unsigned m = 1 << (w - k - 1);
    /* Determine M */
    unsigned M = (m & xsra) << 1;

    return xsra + M;
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

    return xsrl | mask;
}

int sra2(int x, int k)
{
    /* Perform shift logically */
    int xsrl = (unsigned) x >> k;
    /* Determine the width of data type */
    int w = sizeof(int) << 3;

    /* Determine m */
    int m = 1 << (w - k - 1);
    /* Determine M */
    int M = (m & xsrl) << 1;

    return xsrl - M;
}

int main(int argc, char *argv[])
{
    /* Check function srl2 is equal to srl1 or not */
    for (unsigned i = 0; i < UINT_MAX; ++i)
        for (unsigned k = 0; k < 32; ++k)
            assert(srl1(i, k) == srl2(i, k));

    for (unsigned k = 0; k < 32; ++k)
        assert(srl1(UINT_MAX, k) == srl2(UINT_MAX, k));

    /* Check function sra2 is equal to sra1 or not */
    for (int i = INT_MIN; i < INT_MAX; ++i)
        for (int k = 0; k < 32; ++k)
            assert(sra1(i, k) == sra2(i, k));

    for (int k = 0; k < 32; ++k)
        assert(sra1(INT_MAX, k) == sra2(INT_MAX, k));

    return 0;
}