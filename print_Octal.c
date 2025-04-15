#include "main.h"

/**
 * print_octal - Prints an unsigned integer in octal format
 * @n: The unsigned integer to print
 * @count: Pointer to count of characters printed
 */
void print_octal(unsigned int n, int *count)
{
    if (n == 0)  /* Handle the case when n is zero */
    {
        print_char('0', count);
        return;
    }

    /* Recursively print octal digits */
    if (n / 8)
        print_octal(n / 8, count);

    print_char((n % 8) + '0', count);  /* Print the last digit */
}
