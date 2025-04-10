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
    /*Handle unprintable characters (ASCII < 32 or ASCII == 127)*/
    if ((c < 32 || c == 127))
    {
        /*Add special handling for unprintable characters, e.g., escape sequences*/
        snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "\\x%02X", c);
        buffer_index += 4;  /*4 characters for escape sequence (e.g., \x0A)*/

        /*Increment count based on escape sequence length*/
        *count += 4;
    }
    else
    {
        /*Add printable character to the buffer*/
        buffer[buffer_index++] = c;
        (*count)++;
    }

    /*If buffer is full, flush it (write to standard output)*/
    if (buffer_index >= BUFFER_SIZE - 1)
    {
        write(1, buffer, buffer_index);
        buffer_index = 0;  /*Reset buffer after flush*/
    }
}

/*Function to add characters to the buffer without printing yet*/
void add_to_buffer(char c, int *count)
{
    /*Similar to print_char, but without printing immediately*/
    print_char(c, count);
}

/*Function to flush the buffer (write all characters to stdout)*/
void flush_buffer()
{
    if (buffer_index > 0)
    {
        write(1, buffer, buffer_index);
        buffer_index = 0;  /*Reset buffer*/
    }
}

void print_number(int n, int *count)
{
    unsigned int num;

    if (n < 0)
    {
        print_char('-', count);  /*Print the minus sign*/
        num = -n;  /*Handle negative numbers*/
    }
    else
    {
        num = n;
    }

    if (num / 10)  /*Recursively print the digits*/
    {
        print_number(num / 10, count);
    }

    print_char((num % 10) + '0', count);  /*Print the current digit*/
}
