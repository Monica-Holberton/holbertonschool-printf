#include "main.h"
#include <stdio.h>

int main(void)
{

int len1 = _printf("Hello %s! Char: %c Percent: %%\n", "Monica", 'M');
int len2 = printf("Hello %s! Char: %c Percent: %%\n", "Monica", 'M');

_printf("My length: %d\n", len1);
printf("Real length: %d\n", len2);

return (0);
}
