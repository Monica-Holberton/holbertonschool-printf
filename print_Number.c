#include "main.h"
#include <limits.h>

/**
 * print_number - Prints an integer (including handling INT_MIN)
 * @n: The integer to print
 * @count: Pointer to count of characters printed
 */
void print_number(int n, int *count)
{
    unsigned int num;

    if (n < 0)
    {
        print_char('-', count);  /* Print minus sign for negative numbers */
        num = (n == INT_MIN) ? (unsigned int)(INT_MAX) + 1 : (unsigned int)(-n);  /* Handle INT_MIN separately */
    }
    else
    {
        num = (unsigned int)n;
    }

    /* Recursively print digits of num */
    if (num / 10)
        print_number(num / 10, count);

    print_char((num % 10) + '0', count);  /* Print the last digit */
}

/**
 * print_unsigned - Prints an unsigned integer
 * @n: The unsigned integer to print
 * @count: Pointer to count of characters printed
 */
void print_unsigned(unsigned int n, int *count)
{
    /* Recursively print digits of unsigned num */
    if (n / 10)
        print_unsigned(n / 10, count);

    print_char((n % 10) + '0', count);  /* Print the last digit */
}
