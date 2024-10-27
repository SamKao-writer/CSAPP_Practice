#include <assert.h>
#include <stdio.h>

/* Declaration of data type where 4 bytes are packed
 * into an unsigned.
 */
typedef unsigned packed_t;

/* Extract byte from word. Return as signed integer */
int xbyte(packed_t word, int bytenum);

/* Failed attempt at xbyte */
int xbyte(packed_t word, int bytenum)
{
    return (word >> (bytenum << 3)) & 0xFF;
}

int main(int argc, char *argv[])
{
    unsigned x = 0x80808080;
    printf("%d\n", xbyte(x, 0));
    return 0;
}