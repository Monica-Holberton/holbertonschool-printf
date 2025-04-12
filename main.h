#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024  /* Define a buffer size for storing characters*/
#include <stdarg.h>

/*Function prototypes*/
int _printf2(const char *format, ...);
int _printf(const char *format, ...);

void print_char(char c, int *count); /* Prints a character to stdout and updates count */
void print_number(int n, int *count); /* Prints an integer (handles negatives) and updates count */

void add_to_buffer(char c, int *count);  /*Function prototype for add_to_buffer*/
void flush_buffer();  /*Function prototype for flush_buffer*/

void print_binary(unsigned int n, int *count); /* Prints an unsigned int in binary */
void print_octal(unsigned int n, int *count); /* Prints an unsigned int in octal */

void print_unsigned(unsigned int n, int *count);  /* For %u */
void print_hex_lower(unsigned int n, int *count); /* For %x */
void print_hex_upper(unsigned int n, int *count); /* For %X */

#endif /* MAIN_H */
