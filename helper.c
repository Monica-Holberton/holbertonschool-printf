#include "main.h"
#include <unistd.h>

void print_char(char c, int *count) 
{
    write(1, &c, 1);
    (*count)++;
}

void print_number(int n, int *count)
{
	unsigned int num;

	if (n < 0)
	{
		print_char('-', count);
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
	{
		print_number(num / 10, count);
	}

	print_char((num % 10) + '0', count);
}