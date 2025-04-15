#include "main.h"

/**
 * print_long - Prints a long long integer
 * @num: The long long number to print
 * @count: Pointer to count of characters printed
 */
void print_long(long long num, int *count)
{
    if (num < 0)
    {
        print_char('-', count);
        num = -num;
    }

    if (num / 10)
        print_long(num / 10, count);

    print_char((num % 10) + '0', count);
}