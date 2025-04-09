#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf2(const char *format, ...)
{
va_list args;
int count = 0;
char *str;
int i;

if (!format)
return (-1);  /* Null check */

va_start(args, format);

while (*format)
{
if (*format == '%' && *(++format))  /* Check for format specifier */
{
if (*format == 'd' || *format == 'i')  /* Handle %d and %i */
{
int n = va_arg(args, int);
print_number(n, &count);  /* Use helper function for printing numbers */
}
else if (*format == 's')  /* Handle %s */
{
str = va_arg(args, char *);  /* Get string argument */
if (str == NULL)  /* Handle NULL string */
{
str = "(null)";
}

for (i = 0; str[i]; i++)  /* Loop through string */
{
print_char(str[i], &count);  /* Use helper function for printing chars */
}
count += i;  /* Increment count by number of characters printed */
}
else  /* Unknown specifier */
{
print_char('%', &count);
print_char(*format, &count);
}
}
else  /* Print normal char */
{
print_char(*format, &count);
}
format++;
}

va_end(args);
return (count);
}
