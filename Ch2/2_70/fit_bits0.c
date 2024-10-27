#include <assert.h>
#include <stdio.h>

int fit_bits(int x, int n)
{
    int pos = !(x >> (n - 1));
    int neg = (x >> (n - 1)) == -1;
    return pos || neg;
}

int main(int argc, char *argv[])
{
    assert(!fit_bits(3, 1));
    assert(fit_bits(3, 3));
    return 0;
}