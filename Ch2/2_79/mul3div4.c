#include <assert.h>
#include <limits.h>
#include <stdio.h>

int divide_power2(int x, int k)
{
    int sign_mask = INT_MIN;
    int is_neg = x & sign_mask;
    is_neg && (x += ((1 << k) - 1));

    return x >> k;
}

int mul3div4(int x)
{
    /* multiply 3 */
    x = (x << 1) + x;

    /* divide 4 */
    return divide_power2(x, 2);
}

int main(int argc, char *argv[])
{
    for (int i = INT_MIN; i < INT_MAX; ++i)
        assert(mul3div4(i) == i * 3 / 4);
    
    assert(mul3div4(INT_MAX) == INT_MAX * 3 / 4);

    return 0;
}