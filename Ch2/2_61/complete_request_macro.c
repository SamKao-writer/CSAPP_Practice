#include <assert.h>
#include <stdio.h>

#define MASK 0xFF
#define OFFSET ((sizeof(int) - sizeof(char)) << 3)
#define EXP(x) ((x >> OFFSET) | (~MASK))

#define A(x) (!!(x))
#define B(x) (!!(~x))
#define C(x) (A((x) & (MASK)))
#define D(x) (B(EXP(x)))

int main(int argc, char *argv[])
{
    A(0);
    B(0);
    C(0x10);
    D(~0);

    // check macro A
    assert(!A(0));
    assert(A(~0));
    assert(A(2));

    // check macro B
    assert(B(0));
    assert(!B(~0));
    assert(B(0xFF));

    // check macro C
    assert(!C(0));
    assert(C(1));
    assert(!C(0xF00));

    // printf("%d\n", D(~0));
    // check macro D
    assert(!D(~0));
    assert(D(0xFE000000));
    assert(D(0xFF));


    return 0;
}