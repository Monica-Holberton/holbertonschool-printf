#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_length - Handles length modifiers ('h', 'hh', 'l', 'll') for specifiers
 * @args: va_list containing the arguments
 * @specifier: conversion specifier (d, i, u, o, x, X)
 * @length: pointer to current position in format string
 * @count: pointer to output character count
 */
void print_length(va_list args, char specifier, const char *length, int *count)
{
    if (specifier == 'd' || specifier == 'i' || specifier == 'u' || specifier == 'o' || specifier == 'x' || specifier == 'X')
    {
        if (*length == 'h')  /* short or hh */
        {
            if (*(length + 1) == 'h')  /* hh - char */
            {
                char num = (char)va_arg(args, int);  /* `char` is promoted to `int` in va_arg */
                print_short(num, count);  /* Use a function to print short */
            }
            else  /* h - short */
            {
                short num = (short)va_arg(args, int);
                print_short(num, count);  /* Use a function to print short */
            }
        }
        else if (*length == 'l')  /* long or ll */
        {
            if (*(length + 1) == 'l')  /* ll - long long */
            {
                long long num = va_arg(args, long long);
                print_long(num, count);  /* Use a function to print long long */
            }
            else  /* l - long */
            {
                long num = va_arg(args, long);
                print_long(num, count);  /* Use a function to print long */
            }
        }
        else  /* No length modifier, regular int */
        {
            int num = va_arg(args, int);
            print_number(num, count);  /* Use regular print for number */
        }
    }
}
