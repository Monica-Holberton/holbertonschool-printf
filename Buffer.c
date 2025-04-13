#include "main.h"
#include <unistd.h>

static char buffer[BUFFER_SIZE];        /* static: only visible in this file */
static int buffer_index = 0;            /* static: only visible in this file */

/* add_to_buffer - Adds a character to the buffer */
void add_to_buffer(char c, int *count)
{
	if (buffer_index >= BUFFER_SIZE)
		flush_buffer();

	buffer[buffer_index++] = c;
	(*count)++;
}

/* flush_buffer - Flushes the buffer to standard output */
void flush_buffer(void)
{
	if (buffer_index > 0)
	{
		write(1, buffer, buffer_index);
		buffer_index = 0;
	}
}