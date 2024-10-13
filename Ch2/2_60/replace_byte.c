#include <assert.h>
#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b);

int main(int argc, char *argv[])
{
    assert(replace_byte(0x12345678, 2, 0xAB) == 0x12AB5678);
    assert(replace_byte(0x12345678, 0, 0xAB) == 0x123456AB);
    return 0;
}

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    unsigned mask = 0xFF;
    unsigned offset = i << 3;
    return (x & ~(mask << offset)) | (b << offset);
}