#include "main.h"

void print_binary(unsigned int n, int *count)
{
    if (n / 2)
        print_binary(n / 2, count);

    print_char((n % 2) + '0', count);
}
