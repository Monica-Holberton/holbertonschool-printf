#include "main.h"
#include <unistd.h>

char buffer[BUFFER_SIZE];
int buffer_index = 0;

/**
 * add_to_buffer - Adds a character to the buffer and manages buffer flushing
 * @c: The character to be added to the buffer
 * @count: Pointer to the count of characters printed so far
 */
void add_to_buffer(char c, int *count)
{
    /* Add the character to the buffer */
    buffer[buffer_index++] = c;

    /* If buffer is full, flush the buffer to stdout */
    if (buffer_index >= BUFFER_SIZE)
    {
        flush_buffer();
    }

    (*count)++; /* Increment the count of printed characters */
}

/**
 * flush_buffer - Flushes the buffer to the standard output
 */
void flush_buffer(void)
{
    if (buffer_index > 0)
    {
        write(1, buffer, buffer_index);
        buffer_index = 0; /* Reset the buffer index */
    }
}
