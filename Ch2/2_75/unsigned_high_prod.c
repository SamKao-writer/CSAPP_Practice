#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

int signed_high_prod(int x, int y)
{
    int64_t res = (int64_t) x * y;
    return res >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
    unsigned x_mask = x >> 31;
    unsigned y_mask = y >> 31;
    return signed_high_prod(x, y) + x_mask * y + y_mask * x;
}

unsigned unsigned_high_prod_r(unsigned x, unsigned y)
{
    uint64_t res = (uint64_t) x * y;
    return res >> 32;
}


int main(int argc, char *argv[])
{
    unsigned x = 0x12345678;
    unsigned y = 0xFFFFFFFF;
    assert(unsigned_high_prod(x, y) == unsigned_high_prod_r(x, y));
    return 0;
}