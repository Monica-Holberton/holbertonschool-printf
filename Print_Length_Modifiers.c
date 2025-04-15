#include "main.h"
#include <stdarg>
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
    printf("specifier: %c\n", specifier);
    printf("length: %s\n", length);
    printf("count: %d\n", *count);


    if (specifier == 'h')
    {
        if (specifier == 'h')
        {
            length++; /* go to check after h*/
            int num =  va_arg(args, int); 
            /* check number of digits in number*/

            if (*length == 'i' || *length == 'u' || *length == 'd')
            {                        
                short sn = (short) num;
                print_short(num, count);
            }
        }
        else  /* if format is l */
        {
            length++ /* check after l*/
            if (*length == 'l')
            {
                if   
            }
        }
    }
}

