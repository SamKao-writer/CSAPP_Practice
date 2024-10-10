#include <stdio.h>

void show_bytes(unsigned char* start, size_t len);

#define DECLARE_SHOW_BYTES(type)                      \
    static inline void show_##type(type x)            \
    {                                                 \
        show_bytes((unsigned char *)&x, sizeof(type));\
    }

DECLARE_SHOW_BYTES(int);
DECLARE_SHOW_BYTES(double);

int main(int argc, char* argv[]) {
    int a = 0xFF;
    double b = 16;
    show_int(a);
    show_double(b);
    return 0;
}

void show_bytes(unsigned char* start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", *(start + i));
    printf("\n");
}
