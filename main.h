#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

#define BUFFER_SIZE 1024  /* Define Buffer size */

/* ========== Printf Function ========== */
int _printf(const char *format, ...);

/* ========== Character Printing ========== */
void print_char(char c, int *count);

/* ========== Number Printing ========== */
void print_number(int n, int *count);              /* print_number - Prints a signed integer*/
void print_unsigned(unsigned int n, int *count);   /* print_unsigned - Prints an unsigned integer*/

/* ========== Non-Decimal Printing ========== */
void print_binary(unsigned int n, int *count);       /* print_binary - Prints an unsigned int in Binary*/
void print_octal(unsigned int n, int *count);        /* print_octal - Prints an unsigned int in Octal*/
void print_hex(unsigned int n, int *count);          /* print_hex - Prints an unsigned int in lowercase hexadecimal*/
void print_upper_hex(unsigned int n, int *count);    /* print_upper_hex - Prints an unsigned int in UPPERCASE hexadecimal*/

/* ========== Buffer Management ========== */
void add_to_buffer(char c, int *count);       /* add_to_buffer - Adds a character to the buffer*/
void flush_buffer(void);                      /* flush_buffer - Flushes the buffer to standard output*/

/* ========== Precision Support ========== */
int get_precision(const char *format, int *precision);         /* get_precision - Extracts precision from format string*/
void print_number_precision(int n, int precision, int *count); /* print_number_precision - Prints number with precision*/


/*void print_length(va_list args, char specifier, char *length, int *count);*/

void print_reverse(va_list arg, int *count); /*prints a reversed string - *count pointer to an integer to be printed*/

#endif /* MAIN_H */
