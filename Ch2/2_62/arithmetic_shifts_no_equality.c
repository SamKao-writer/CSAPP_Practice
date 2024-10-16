#include <stdio.h>

int int_shifts_are_arithmetic(void)
{
    int num = ~0;
    return !(num ^ (num >> 1));
}

int main(int argc, char *argv[])
{
    printf("%d\n", int_shifts_are_arithmetic());
    return 0;
}