#include "main.h"

char buffer[BUFFER_SIZE];
int buffer_index = 0;

/**
 * add_to_buffer - Adds a character to the buffer and flushes if full
 * @c: Character to add
 * @count: Pointer to character count to update
 */
void add_to_buffer(char c, int *count)
{
    buffer[buffer_index++] = c;
    (*count)++;  /* Increment the character count */

    if (buffer_index >= 1024 - 1)
        flush_buffer();
}

/**
 * flush_buffer - Writes buffer to stdout and resets buffer
 */
void flush_buffer(void)
{
    if (buffer_index > 0)
    {
        write(1, buffer, buffer_index);
        buffer_index = 0;
    }
}