#include <assert.h>
#include <stdio.h>
#include <string.h>

/* Copy integer into buffer if space is acailable */
/* WARNING: The following code is buggy */
void copy_int(int val, void *buf, int maxbytes)
{
    if (maxbytes - sizeof(val) >= 0)
        memcpy(buf, (void *) &val, sizeof(val));
}

void copy_int_r(int val, void *buf, int maxbytes)
{
    if (maxbytes >= (int) sizeof(val))
        memcpy(buf, (void *) &val, sizeof(val));
}

int main(int argc, char *argv[])
{
    return 0;
}