#include <stdio.h>
#include <assert.h>
#include <stdint.h>

#define DATATYPE_LIST  \
    X(8)               \
    X(16)              \
    X(32)              \
    X(64)

/* Function prototype */
#define X(num) static inline uint##num##_t rotate_left_##num(uint##num##_t x, int n);
DATATYPE_LIST
#undef X

/* Function definition */
#define X(num)              \
    static inline uint##num##_t rotate_left_##num(uint##num##_t x, int n) \
    {                                                                     \
        int w = (int)(sizeof(uint##num##_t) << 3);                        \
        return (x << n) | (x >> (w - n - 1) >> 1);                        \
    }
    DATATYPE_LIST
#undef X

unsigned rotate_left(unsigned x, int n)
{
    int w = (int)(sizeof(unsigned) << 3);
    return (x << n) | (x >> (w - n - 1) >> 1);
}

int main(int argc, char *argv[])
{
    // assert(rotate_left_32(0x12345678, 4) == 0x23456781);
    // assert(rotate_left_32(0x12345678, 20) == 0x67812345);
    for (uint32_t i = 0; i < UINT32_MAX; ++i) {
        for (int j = 0; j <= 32; ++j) {
            assert(rotate_left_32(i, j) == rotate_left(i, j));
        }
    }

    return 0;
}