#include "main.h"

/**
 * print_char - Prints a single character
 * @c: Character to be printed
 * @count: Pointer to the count of printed characters
 */
void print_char(char c, int *count)
{
    add_to_buffer(c, count); /* Add character to buffer */
}