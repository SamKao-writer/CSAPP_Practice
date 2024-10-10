#include <stdio.h>

void show_bytes(unsigned char *start, size_t len);
void show_int(int x);
void show_double(double x);
void show_pointer(void *x);
void test_show(int val);

int main(int argc, char *argv[])
{
    int test_num = 328;

    test_show(test_num);

    return 0;
}

void show_bytes(unsigned char *start, size_t len)
{
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", *(start + i));
    printf("\n");
}

void show_int(int x)
{
    show_bytes((unsigned char *) &x, sizeof(int));
}

void show_double(double x)
{
    show_bytes((unsigned char *) &x, sizeof(double));
}

void show_pointer(void *x)
{
    show_bytes((unsigned char *) &x, sizeof(void *));
}

void test_show(int val)
{
    int ival = val;
    double dval = (double) val;
    void *p = (void *) &val;

    show_int(ival);
    show_double(dval);
    show_pointer(p);
}
