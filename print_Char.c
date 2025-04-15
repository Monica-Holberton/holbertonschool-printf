#include "main.h"
#include <unistd.h>

/**
 * print_char - Prints a single character, handles non-printable characters
 * @c: Character to be printed
 * @count: Pointer to the count of printed characters
 */
void print_char(char c, int *count)
{
    /* Check if the character is a non-printable character */
    if (c < 32 || c == 127)
    {
        /* Handle non-printable character by printing in hexadecimal format */
        buffer[buffer_index++] = '\\';  /* Start escape sequence */
        buffer[buffer_index++] = 'x';   /* Hexadecimal escape character */
        buffer[buffer_index++] = "0123456789ABCDEF"[c / 16];  /* First hex digit */
        buffer[buffer_index++] = "0123456789ABCDEF"[c % 16];  /* Second hex digit */
    }
    else
    {
        /* Handle printable character normally */
        buffer[buffer_index++] = c;
    }
    
    (*count)++;  /* Increment the character count */

    /* If buffer is full, flush it to the output */
    if (buffer_index >= BUFFER_SIZE - 1)
    {
        write(1, buffer, buffer_index);  /* Write the buffer content to stdout */
        buffer_index = 0;  /* Reset the buffer index */
    }
}
