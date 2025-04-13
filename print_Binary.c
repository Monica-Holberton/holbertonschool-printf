#include "main.h"

void print_binary(unsigned int n, int *count)
{
    if (n / 2)
        print_binary(n / 2, count);
    add_to_buffer((n % 2) + '0', count);  /* Convert the binary digits to characters */
}
