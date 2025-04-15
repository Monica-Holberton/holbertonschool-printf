#include "main.h"
#include <limits.h>

/**
 * print_long - Prints a long long integer
 * @num: The long long number to print
 * @count: Pointer to count of characters printed
 */
void print_long(long num, int *count)
{
    if (num == LLONG_MIN)  /* Handle edge case for LLONG_MIN */
    {
        print_char('-', count);
        num = 9223372036854775807;  /* Set num to LLONG_MAX */
    }

    if (num < 0)  /* If number is negative, handle as a regular case */
    {
        print_char('-', count);
        num = -num;
    }

    if (num / 10)  /* Recursively print digits */
        print_long(num / 10, count);

    print_char((num % 10) + '0', count);  /* Print the last digit */
}
