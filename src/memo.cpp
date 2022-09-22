#include <stdio.h>

int main()
{
    int a = 32815, i;
    // printf("%x %X\n", ((char *)&a), *((char *)&a));
    // printf("%x %X\n", ((char *)&a + 1), *((char *)&a + 1));
    // printf("%x %X\n", ((char *)&a + 2), *((char *)&a + 2));
    // printf("%x %X\n", ((char *)&a + 3), *((char *)&a + 3));
    // printf("\n%X", a);

    char *p = (char *)&a;
    for (i = 0; i < 4; i++)
    {
        printf("%X ", *(p + i));
    }
}