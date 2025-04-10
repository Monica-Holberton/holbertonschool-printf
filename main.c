#include <stdio.h>
#include "main.h"

int main(void)
{
    int len1, len2;

    len1 = _printf("%%");
    len2 = printf("%%");

    printf("Length of _printf output: %d\n", len1);
    printf("Length of printf output: %d\n", len2);

    return 0;
}
