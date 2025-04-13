#include "main.h"
#include <unistd.h>

void print_char(char c, int *count)
{
    if (c < 32 || c == 127)
    {
        buffer[buffer_index++] = '\\';
        buffer[buffer_index++] = 'x';
        buffer[buffer_index++] = "0123456789ABCDEF"[c / 16];
        buffer[buffer_index++] = "0123456789ABCDEF"[c % 16];
    }
    else
    {
        buffer[buffer_index++] = c;
    }
    (*count)++;

    if (buffer_index >= BUFFER_SIZE - 1)
    {
        write(1, buffer, buffer_index);
        buffer_index = 0;
    }
}
