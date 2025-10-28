#include <assert.h>
#include <limits.h>
#include <stdio.h>

unsigned srl(unsigned x, int k)
{
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;

    /* Can't use right shift, but can use left shift */
    int lshift_amount = (int) (sizeof(int) << 3) - k;

    /* Since shift amount can't be bigger than 31, use bit mask to get correct
     * amount to avoid UB */
    unsigned tmp_mask = (sizeof(int) << 3) - 1;

    lshift_amount &= tmp_mask;

    /* Get the real mask we need */
    unsigned mask = (!!(lshift_amount) << (lshift_amount)) - 1;

    /* Get the answer */
    return xsra & mask;
}

int sra(int x, int k)
{
    /* Perform shift logically */
    int xsrl = (unsigned) x >> k;

    /* Can't use right shift, but we can use left shift */
    int lshift_amount = (int) (sizeof(int) << 3) - k;

    /* Since shift amount can't be bigger than 31, use bit mask to get correct
     * amount to avoid UB*/
    unsigned tmp_mask = (sizeof(int) << 3) - 1;

    lshift_amount &= tmp_mask;

    /* Get the real mask we need */
    unsigned negative = !!(x & INT_MIN);
    unsigned mask = ((negative & !!(lshift_amount)) << lshift_amount) - 1;

    return xsrl | ~(mask);
}

int main()
{
    /* For testing srl */
    for (int k = 0; k < 32; ++k) {
        for (unsigned i = 0; i < UINT_MAX; i++) {
            unsigned val = srl(i, k);
            assert(val == (i >> k));
        }

        unsigned i = UINT_MAX;
        unsigned val = srl(i, k);
        assert(val == (i >> k));
        printf("srl: k = %d is passed\n", k);
    }

    /* For testing sra*/
    for (int k = 0; k < 32; ++k) {
        for (int i = INT_MIN; i < INT_MAX; ++i) {
            int val = sra(i, k);
            assert(val == (i >> k));
        }

        int i = INT_MAX;
        int val = srl(i, k);
        assert(val == (i >> k));
        printf("sra: k = %d is passed\n", k);
    }

    printf("All test cases are passed!!!\n");
    return 0;
}