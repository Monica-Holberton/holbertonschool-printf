#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024  /* Define a buffer size for output buffering */

#include <stdarg.h>

/* Function Prototypes */
int _printf(const char *format, ...);

/* Print helpers */
void print_char(char c, int *count);
void print_number(int n, int *count);

/* Buffer handlers */
void add_to_buffer(char c, int *count);
void flush_buffer();

/* Non-decimal specifiers */
void print_binary(unsigned int n, int *count);
void print_octal(unsigned int n, int *count);
void print_unsigned(unsigned int n, int *count);
void print_hex(unsigned int n, int *count);
void print_upper_hex(unsigned int n, int *count);

/* Precision handlers */
int get_precision(const char *format, int *precision);
void print_number_precision(int n, int precision, int *count);

#endif /* MAIN_H */
