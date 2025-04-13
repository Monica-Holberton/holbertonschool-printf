#include "main.h"

void print_hex(unsigned int n, int *count)
{
    if (n / 16)
        print_hex(n / 16, count);

    print_char("0123456789abcdef"[n % 16], count);
}

void print_upper_hex(unsigned int n, int *count)
{
    if (n / 16)
        print_upper_hex(n / 16, count);

    print_char("0123456789ABCDEF"[n % 16], count);
}
