#include <assert.h>
#include <stdio.h>

int A(int x);
int B(int x);
int C(int x);
int D(int x);

int main(int argc, char *argv[])
{
    // check function A
    assert(!A(0));
    assert(A(~0));
    assert(A(2));

    // check function B
    assert(B(0));
    assert(!B(~0));
    assert(B(0xFF));

    // check function C
    assert(!C(0));
    assert(C(1));
    assert(!C(0xF00));

    // check function D
    assert(!D(~0));
    assert(D(0xFE000000));
    assert(D(0xFF));

    return 0;
}

int A(int x)
{
    return !!x;
}

int B(int x)
{
    return !!(~x);
}

int C(int x)
{
    x = x & 0xFF;
    return A(x);
}

int D(int x)
{
    x = x >> ((sizeof(int) - sizeof(char)) << 3) | ~0xFF;
    return B(x);
}
