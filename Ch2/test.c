#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <stdint.h>
  
#define __DECLARE_ROTATE(bits, type)                   \
    static inline type rotl##bits(const type v, int c) \
    {                                                  \
        const int mask = (bits) - (1);                 \
        c &= mask;                                     \
                                                       \
        return (v << c) | (v >> (-c & mask));          \
    }                                                  \
                                                       \
    static inline type rotr##bits(const type v, int c) \
    {                                                  \
        const int mask = (bits) - (1);                 \
        c &= mask;                                     \
                                                       \
        return (v >> c) | (v << (-c & mask));          \
    }

#define DECLARE_ROTATE(bits) __DECLARE_ROTATE(bits, uint##bits##_t)

DECLARE_ROTATE(64);
DECLARE_ROTATE(32);
DECLARE_ROTATE(16);
DECLARE_ROTATE(8);

int main(int argc, char *argv[])
{
    
    return 0;
}