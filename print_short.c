#include "main.h"
#include <stdlib.h>

/**
 * print_short - Prints a short integer
 * @n: The short integer to print
 * @count: Pointer to the character count
 *
 * Return: Number of characters printed
 */
int print_short(short n, int *count)
{
    char short_number[6];  /* Buffer to hold up to 5 digits for a short number */
    int i = 0;

    if (n == 0)
    {
        print_char('0', count);  /* Handle zero explicitly */
        return 1;  /* One character printed */
    }

    if (n < 0)
    {
        print_char('-', count);  /* Print the minus sign */
        n = -n;  /* Make n positive for further processing */
    }

    while (n)
    {
        short_number[i] = n % 10 + '0';  /* Get the next digit */
        n /= 10;  /* Reduce n */
        i++;
    }

    while (i--)  /* Print digits in reverse order */
    {
        add_to_buffer(short_number[i], count);  /* Add each digit to buffer */
    }

    return *count;  /* Return the character count */
}
