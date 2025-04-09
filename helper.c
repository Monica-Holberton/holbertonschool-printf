#include "main.h"
#include <unistd.h>

void print_char(char c, int *count) 
{
    write(1, &c, 1);
    (*count)++;
}

void print_number(int n, int *count)
{
    int div = 1;
    char d;

    if (n < 0)
    {
        print_char('-', count);
        n = -n;
    }
    while (n / div > 9) 
        div *= 10;
    while (div) 
    {
        d = '0' + (n / div % 10);
        print_char(d, count);
        div /= 10;
    }
}
