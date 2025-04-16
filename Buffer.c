#include "main.h"
#include <unistd.h>

char buffer[BUFFER_SIZE];
int buffer_index = 0;

/**
 * add_to_buffer - Adds a character to the buffer and flushes if needed
 * @c: Character to add
 * @count: Pointer to character count
 */
void add_to_buffer(char c, int *count)
 {
     buffer[buffer_index++] = c;
     (*count)++;
 
     if (buffer_index >= BUFFER_SIZE)
     {
         flush_buffer();
     }
 }
 
 /**
  * flush_buffer - Flushes the buffer to stdout
  */
void flush_buffer(void)
 {
     if (buffer_index > 0)
     {
         write(1, buffer, buffer_index);
         buffer_index = 0;
     }
 }
