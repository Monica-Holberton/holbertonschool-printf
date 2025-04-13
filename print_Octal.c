#include "main.h"

void print_octal(unsigned int n, int *count)
{
    if (n / 8)
        print_octal(n / 8, count);

    print_char((n % 8) + '0', count);
}
