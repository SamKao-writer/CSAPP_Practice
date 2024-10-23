#include <stdio.h>

/* The following code does not run properly on some machines */
int bad_int_size_is_32()
{
    /* Set most significant bit (msb) of 32-bit machines */
    int set_msb = 1 << 31;
    /* Shift past msb of 32-bit word */
    int beyond_msb = 1 << 32;

    /* set_msb is nonzero when word size >= 32 
       beyond_msb is zero when word size <= 32 */
    return set_msb && !beyond_msb;
}

int main(int argc, char *argv[])
{
    printf("%d\n", bad_int_size_is_32());
    return 0;
}