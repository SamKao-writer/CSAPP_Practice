#include <stdio.h>

void show_bytes(unsigned char *start, size_t len);

#define DATATYPE_LIST \
    X(int)            \
    X(double)

#define X(type) static inline void show_##type(type x);
    DATATYPE_LIST
#undef X

#define X(type)                                         \
    static inline void show_##type(type x)              \
    {                                                   \
        show_bytes((unsigned char *) &x, sizeof(type)); \
    }
    DATATYPE_LIST
#undef X

int main(int argc, char *argv[])
{
    int a = 0xFF;
    double b = 16;
    show_int(a);
    show_double(b);
    return 0;
}

void show_bytes(unsigned char *start, size_t len)
{
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", *(start + i));
    printf("\n");
}