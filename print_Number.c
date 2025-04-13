#include "main.h"
#include <limits.h>

void print_number(int n, int *count)
{
    unsigned int num;

    if (n < 0)
    {
        print_char('-', count);
        num = (n == INT_MIN) ? (unsigned int)(INT_MAX) + 1 : (unsigned int)(-n);
    }
    else
    {
        num = (unsigned int)n;
    }

    if (num / 10)
        print_number(num / 10, count);

    print_char((num % 10) + '0', count);
}

void print_unsigned(unsigned int n, int *count)
{
    if (n / 10)
        print_unsigned(n / 10, count);

    print_char((n % 10) + '0', count);
}
