#include <assert.h>
#include <stdio.h>

int int_size_is_32()
{
    unsigned set_msb = 1 << 31;
    unsigned beyond_msb = set_msb << 1;

    return (int) (set_msb && !beyond_msb);
}

int main(int argc, char *argv[])
{
    printf("%d\n", int_size_is_32());
    return 0;
}