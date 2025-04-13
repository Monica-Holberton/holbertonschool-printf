#include "main.h"
#include <unistd.h>

/**
 * get_precision - Parses precision value from format string
 * @format: Pointer to the precision digits (after '.')
 * @precision: Pointer to store the parsed precision
 *
 * Return: Number of characters read (digits only)
 */
int get_precision(const char *format, int *precision)
{
    int value = 0, len = 0;

    while (format[len] >= '0' && format[len] <= '9')
    {
        value = value * 10 + (format[len] - '0');
        len++;
    }

    *precision = value;
    return len;
}

/**
 * print_number_precision - Prints a number with specified precision
 * @n: The integer to print
 * @precision: Minimum number of digits to print
 * @count: Pointer to the character count
 */
void print_number_precision(int n, int precision, int *count)
{
    unsigned int num;
    int num_len = 0;
    char buffer[20]; /* Enough to hold an int */
    int i;

    if (n < 0)
    {
        print_char('-', count);
        num = -n;
    }
    else
    {
        num = n;
    }

    /* Convert number to string in reverse */
    do {
        buffer[num_len++] = (num % 10) + '0';
        num /= 10;
    } while (num > 0);

    /* Add leading zeros if needed */
    for (i = 0; i < (precision - num_len); i++)
        print_char('0', count);

    /* Print digits in correct order */
    while (num_len--)
        print_char(buffer[num_len], count);
}