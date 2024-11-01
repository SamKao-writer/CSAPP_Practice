#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_calloc(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0)
        return NULL;

    size_t total = nmemb * size;
    if (size == total / nmemb) {
        void *space = malloc(total);
        memset(space, 0, total);
        return space;
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    return 0;
}