#include "main.h"

/**
 * print reverser : prints a string in reverse
 * @args: List of Arguments 
 *
 * Return: Number of printed charachters
 */

int print_reverse(va_list args)
{
	char *str = va_args(args, char *);
	int len = 0, i;

	while(str[len])
		len++;

	for (i = len - 1; i >= 0; i--)
		write(1, &str[i], 1);
	return (len);
}
