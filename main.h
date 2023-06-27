main.h

#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

int _printf(const char *format, ...);
int _print_string(char *buffer, char *str);
int _print_integer(char *buffer, int n);
int _print_unsigned_integer(char *buffer, unsigned int n);
int _print_octal(char *buffer, unsigned int n);
int _print_hexadecimal(char *buffer, unsigned int n, int uppercase);
int _putchar(char c);
int _print_unsigned_integer(unsigned int n);
int _print_octal(unsigned int n);
int _print_hexadecimal(unsigned int n, int uppercase);
int _print_integer(int n);
int _print_string(char *str);

int _print_string(char *str, int width, int precision, int zero_flag);
int _print_integer(int n, int width, int precision, int zero_flag);
int _print_unsigned_integer(unsigned int n, int width, int precision, int zero_flag);
int _print_octal(unsigned int n, int width, int precision, int zero_flag);
int _print_hexadecimal(unsigned int n, int width, int precision, int uppercase, int zero_flag);
int _print_pointer(void *ptr, int width, int precision, int zero_flag);
int print_with_flags(const char *format, va_list args, char *flags, int width, int precision, int zero_flag);
int print_with_precision(const char *format, va_list args, char *flags, int width, int precision, int zero_flag);
const char *parse_format(const char *format, char *flags, int *width, int *precision, int *zero_flag, char *specifier);
int _strlen(const char *str);
void _reverse_string(char *str);
void _rot13_string(char *str);
int _print_custom(const char *format, ...);
int _print_integer_length(va_list args, char length_modifier);
int _print_unsigned_length(va_list args, char length_modifier);

#endif /* MAIN_H */
