#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

#define DATATYPE_LIST \
    X(8)              \
    X(16)             \
    X(32)             \
    X(64)

/* Function prototype */
#define X(num)                                                      \
    static inline int##num##_t saturating_add_##num(int##num##_t x, \
                                                    int##num##_t y);
DATATYPE_LIST
#undef X

/* Function definition */
#define X(num)                                                                 \
    static inline int##num##_t saturating_add_##num(int##num##_t x,            \
                                                    int##num##_t y)            \
    {                                                                          \
        int##num##_t sum = x + y;                                              \
        int##num##_t mask = INT##num##_MIN;                                    \
        int##num##_t pos_overflow =                                            \
            !(x & mask) && !(y & mask) && (sum & mask);                        \
        int##num##_t neg_overflow = (x & mask) && (y & mask) && !(sum & mask); \
        (pos_overflow && (sum = INT##num##_MAX)) ||                            \
            (neg_overflow && (sum = INT##num##_MIN));                          \
        return sum;                                                            \
    }
DATATYPE_LIST
#undef X

/* original version of saturating addition */
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
    // for (int32_t i = INT32_MIN; i < INT32_MIN + 100000; ++i)
    //     for (int32_t j = INT32_MIN; j < INT32_MIN + 100000; ++j)
    //         assert(saturating_add_32(i, j) == saturating_add(i, j));

    for (int32_t j = INT32_MIN; j < INT32_MAX; ++j)
        assert(saturating_add_32(INT32_MAX, j) == saturating_add(INT32_MAX, j));

    return 0;
}