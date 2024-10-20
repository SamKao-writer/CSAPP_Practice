#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

/* Define X */
#define DATATYPE_LIST \
    X(8)              \
    X(16)             \
    X(32)

/* Define function prototype */
#define X(num) static inline int odd_ones_##num(uint##num##_t x);
DATATYPE_LIST
#undef X

/* Function definition */
#define X(num)                                        \
    static inline int odd_ones_##num(uint##num##_t x) \
    {                                                 \
        for (uint32_t i = 1; i < num; i *= 2)         \
            x ^= x >> i;                              \
        return x & 0x1;                               \
    }
DATATYPE_LIST
#undef X

int odd_ones_0(unsigned x)
{
    x ^= x >> 1;
    x ^= x >> 2;
    x ^= x >> 4;
    x ^= x >> 8;
    x ^= x >> 16;

    return x & 0x1;
}

int main(int argc, char *argv[])
{
    for (unsigned i = 0; i < UINT32_MAX; ++i)
        assert(odd_ones_0(i) == odd_ones_32(i));

    return 0;
}