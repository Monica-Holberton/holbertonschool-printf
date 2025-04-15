#include "main.h"

/* print_hex - Prints an unsigned int in hexadecimal (lowercase or uppercase) */
void print_hex(unsigned int n, int *count, int uppercase)
{
    char *hex_digits_lower = "0123456789abcdef";
    char *hex_digits_upper = "0123456789ABCDEF";
    char *hex_digits = uppercase ? hex_digits_upper : hex_digits_lower;

    if (n >= 16)
        print_hex(n / 16, count, uppercase);

    add_to_buffer(hex_digits[n % 16], count); /* Add the hex digit to the buffer */
}
