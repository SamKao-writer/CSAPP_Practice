#include <assert.h>
#include <limits.h>
#include <stdio.h>

/* Divide by power of 2. Assume 0 <= k < w-1 */
int divide_power2(int x, int k)
{
    int sign_mask = INT_MIN;
    int is_neg = x & sign_mask;
    is_neg && (x += ((1 << k) - 1));

    return x >> k;
}

int pow_2(int x, int k)
{
    int res = 1;
    for (int i = 1; i <= k; ++i)
        res *= x;
    return res;
}

int main(int argc, char *argv[])
{
    for (int i = INT_MIN; i < INT_MAX; ++i)
        for (int j = 0; j < 31; ++j)
            assert(divide_power2(i, j) == i / pow_2(2, j));

    for (int j = 0; j < 31; ++j)
        assert(divide_power2(INT_MAX, j) == INT_MAX / pow_2(2, j));

    return 0;
}