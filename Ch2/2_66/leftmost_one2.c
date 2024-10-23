#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

#define DATATYPE_LIST \
    X(8)              \
    X(16)             \
    X(32)             \
    X(64)

/* Define function prototype */
#define X(num) static inline uint##num##_t leftmost_one_##num(uint##num##_t x);
DATATYPE_LIST
#undef X

/* Function definition */
#define X(num)                                                      \
    static inline uint##num##_t leftmost_one_##num(uint##num##_t x) \
    {                                                               \
        for (uint32_t i = 1; i < num; i *= 2)                       \
            x |= x >> i;                                            \
        return x ^ (x >> 1);                                        \
    }
DATATYPE_LIST
#undef X

int leftmost_one0(unsigned x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return x ^ (x >> 1);
}

int main(int argc, char *argv[])
{
    for (unsigned i = 0; i < UINT_MAX; ++i)
        assert(leftmost_one_32(i) == leftmost_one0(i));

    return 0;
}