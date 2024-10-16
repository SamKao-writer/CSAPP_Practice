#include <stdio.h>

int int_shifts_are_arithmetic(void)
{
    int mask = ~0;
    return mask == (mask >> 1);
}

int main(int argc, char *argv[])
{
    printf("%d\n", int_shifts_are_arithmetic());
    return 0;
}