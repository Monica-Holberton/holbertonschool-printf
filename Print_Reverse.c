#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * Print_Reverse : prints a string in reverse
 * @args: List of Arguments 
 *
 * Return: Number of printed charachters
 */

int print_reverse(va_list args, int *count)
{
	char *str = va_args(args, char *);
	int len = 0, i;

	while(str[len])
		len++;

	for (i = len - 1; i >= 0; i--)
    print_char(str[i], count); /* Print each character and update count */
	return (len); /*Return count*/
}
