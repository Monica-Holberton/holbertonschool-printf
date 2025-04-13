#include "main.h"
#include <unistd.h>

char buffer[BUFFER_SIZE];
int buffer_index = 0;

void flush_buffer(void)
{
    if (buffer_index > 0)
    {
        write(1, buffer, buffer_index);
        buffer_index = 0;
    }
}