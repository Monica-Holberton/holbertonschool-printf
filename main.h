#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

extern char buffer[BUFFER_SIZE];
extern int buffer_index;

/* ========== Printf Function ========== */
int _printf(const char *format, ...);

/* ========== Character Printing ========== */
void print_char(char c, int *count);

/* ========== Number Printing ========== */
void print_unsigned(unsigned int n, int *count);    /* print_unsigned - Prints an unsigned integer */
void print_long(long num, int *count);              /* Prints long or long long integers for %d and %i */
void print_number(int n, int *count);               /* print_number - Prints an integer */
int print_short(short n, int *count);               /* print_short - Prints a signed short */

/* ========== Non-Decimal Binary & Octal ========== */
void print_binary(unsigned int n, int *count);      /* print_binary - Prints an unsigned int in Binary */
void print_octal(unsigned int n, int *count);       /* print_octal - Prints an unsigned int in Octal */

/* ========== HEX ========== */
void print_hex(unsigned int n, int *count, int uppercase); /* Prints an unsigned int in hex-lower or upper case */

/* ========== Buffer Management ========== */
void add_to_buffer(char c, int *count);             /* Adds a character to the buffer */
void flush_buffer(void);                            /* Flushes the buffer to standard output */

/* ========== Precision ========== */
int get_precision(const char *format, int *precision);        /* Extracts precision from format string */
void print_number_precision(int n, int precision, int *count); /* Prints number with precision */

/* ========== Length Modifiers ========== */
void print_length(va_list args, char specifier, const char *length, int *count);

/* ========== String Reversal ========== */
void print_reverse(va_list args, int *count);  /* Prints a string in reverse */

/* ========== Print Pointers ========== */
void print_pointer(va_list args, int *count);

/* ==== Print String - Non Printable ===== */
void print_string(va_list args, int *count);

/* ========== ROT 13 ========== */
void print_rot13(va_list args, int *count);


#endif /* MAIN_H */
