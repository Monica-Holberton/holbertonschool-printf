#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024  /* Define a buffer size for storing characters*/

/*Global buffer to store characters*/
char buffer[BUFFER_SIZE];
int buffer_index = 0;

/*Function to print a character and add it to the buffer*/
void print_char(char c, int *count)
{

/* Check if the character is unprintable or non-ASCII */
if (c < 32 || c == 127)
{
    /* Handle the unprintable character by adding escape sequence to buffer manually */
    buffer[buffer_index++] = '\\';
    buffer[buffer_index++] = 'x';
    buffer[buffer_index++] = "0123456789ABCDEF"[c / 16];
    buffer[buffer_index++] = "0123456789ABCDEF"[c % 16];

    buffer[buffer_index++] = c;
    (*count) += 1;  /* Increment count for the unprintable character (as 1) */
}
else
{
    /* Print printable character directly */
    buffer[buffer_index++] = c;
    (*count) += 1;  /* Increment count for printable characters */
}

    /* If buffer is full, flush it (write to standard output) */
    if (buffer_index >= BUFFER_SIZE - 1)
    {
        write(1, buffer, buffer_index);
        buffer_index = 0;  /* Reset buffer after flush */
    }
}

/*Function to add characters to the buffer without printing yet*/
void add_to_buffer(char c, int *count)
{
    /* Similar to print_char, but without printing immediately */
    print_char(c, count);
}

/*Function to flush the buffer (write all characters to stdout)*/
void flush_buffer()
{
    if (buffer_index > 0)
    {
        write(1, buffer, buffer_index);
        buffer_index = 0;  /* Reset buffer */
    }
}

void print_number(int n, int *count)
{
    unsigned int num;

    if (n < 0)
    {
        print_char('-', count);  /* Print the minus sign */
        num = -n;  /* Handle negative numbers */
    }
    else
    {
        num = n;
    }

    if (num / 10)  /* Recursively print the digits */
    {
        print_number(num / 10, count);
    }

    print_char((num % 10) + '0', count);  /* Print the current digit */
}
/*
* print_binary - Converts and prints an unsigned int in binary
* @n: The number to convert
* @count: Pointer to character count
*/

/* Function to print an unsigned integer in binary */
void print_binary(unsigned int n, int *count)
{
    if (n / 2)
        print_binary(n / 2, count);

    print_char((n % 2) + '0', count);
}

/* Function to print an unsigned integer in octal */
void print_octal(unsigned int n, int *count)
{
    if (n / 8)
        print_octal(n / 8, count);

    print_char((n % 8) + '0', count);
}

