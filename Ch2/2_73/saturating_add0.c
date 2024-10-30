#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

/* Addition that saturates to TMin or TMax */
int saturating_add(int x, int y)
{
    int sum = x + y;
    int mask = INT_MIN;
    int pos_overflow = !(x & mask) && !(y & mask) && (sum & mask);
    int neg_overflow = (x & mask) && (y & mask) && !(sum & mask);

    (pos_overflow && (sum = INT_MAX)) || (neg_overflow && (sum = INT_MIN));
    return sum;
}

int main(int argc, char *argv[])
{
    assert(saturating_add(INT_MIN, -1) == INT_MIN);
    assert(saturating_add(INT_MAX, 1) == INT_MAX);
    return 0;
}