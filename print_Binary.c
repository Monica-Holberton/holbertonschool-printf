#include "main.h"

/**
 * print_binary - Prints the binary representation of an unsigned integer
 * @n: The unsigned integer to convert and print
 * @count: Pointer to the count of characters printed
 */
void print_binary(unsigned int n, int *count)
{
    if (n / 2)  /* If n is greater than 1, keep dividing by 2 */
        print_binary(n / 2, count);  /* Recursive call for the next bit */

    /* Add the current bit (n % 2) to the buffer */
    print_char((n % 2) + '0', count);  /* Convert 0 or 1 to '0' or '1' and print */
}
