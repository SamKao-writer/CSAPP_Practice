#include <assert.h>
#include <limits.h>
#include <stdio.h>

/* Determine whether arguments can be subtracted without overflow
 * This function should return 1 if the computation of x-y does not overflow
 */
int tsub_ok(int x, int y)
{
    int sum = x - y;
    int mask = INT_MIN;
    int pos_overflow = !(x & mask) && (y & mask) && (sum & mask);
    int neg_overflow = (x & mask) && !(y & mask) && !(sum & mask);
    return !pos_overflow && !neg_overflow;
}

int main(int argc, char *argv[])
{
    assert(!tsub_ok(INT_MAX, -1));
    assert(!tsub_ok(INT_MIN, 1));
    assert(tsub_ok(INT_MAX, 1));
    assert(tsub_ok(INT_MIN, -1));
    assert(!tsub_ok(0, INT_MIN));
    assert(tsub_ok(0, INT_MAX));
    assert(tsub_ok(INT_MIN, 0));
    assert(tsub_ok(INT_MAX, 0));

    return 0;
}