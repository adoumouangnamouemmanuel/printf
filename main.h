#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)

/* Flag definitions */
#define F_MINUS  (1 << 0)
#define F_PLUS   (1 << 1)
#define F_ZERO   (1 << 2)
#define F_HASH   (1 << 3)
#define F_SPACE  (1 << 4)

/* Size definitions */
#define NEW_LONG 2
#define NEW_SHORT 1

/* Function prototypes */
int _printf(const char *format, ...);
int _putchar(char c);
int get_active_flags(const char *format, int *index);
int calculate_precision(const char *format, int *index, va_list args);
int get_size(const char *format, int *index);
int get_width(const char *format, int *index, va_list list);
int handle_argument(const char *format, int *index, va_list args, char buffer[], int active_flags,
                    int print_width, int print_precision, int cast_size);
int print_character(va_list args, char buffer[], int active_flags, int print_width, int print_precision, int cast_size);
int print_string(va_list args, char buffer[], int active_flags, int print_width, int print_precision, int cast_size);
int print_integer(va_list args, char buffer[], int active_flags, int print_width, int print_precision, int cast_size);
int print_unsigned_integer(va_list args, char buffer[], int active_flags, int print_width, int print_precision, int cast_size);
int print_hexadecimal(va_list args, char buffer[], int active_flags, int print_width, int print_precision, int cast_size);
int print_octal(va_list args, char buffer[], int active_flags, int print_width, int print_precision, int cast_size);
int print_binary(va_list args, char buffer[], int active_flags, int print_width, int print_precision, int cast_size);
int print_pointer(va_list args, char buffer[], int active_flags, int print_width, int print_precision, int cast_size);
int print_non_printable(va_list args, char buffer[], int active_flags, int print_width, int print_precision, int cast_size);
int print_reverse(va_list args, char buffer[], int active_flags, int print_width, int print_precision, int cast_size);
int print_rot13string(va_list args, char buffer[], int active_flags, int print_width, int print_precision, int cast_size);
int write_buffer(char buffer[], int buffer_length);
int write_character(char c, int print_width, int active_flags);
int write_string(char *str, int print_width, int active_flags, int print_precision);
int write_integer(char *num_str, int num_length, int print_width, int active_flags, int print_precision);
int write_unsigned_integer(char *num_str, int num_length, int print_width, int active_flags, int print_precision);
int write_hexadecimal(char *num_str, int num_length, int print_width, int active_flags, int print_precision, int uppercase);
int write_octal(char *num_str, int num_length, int print_width, int active_flags, int print_precision);
int write_binary(char *num_str, int num_length, int print_width, int active_flags, int print_precision);
int write_pointer(char buffer[], int start_index, int length, int print_width, int active_flags, char padd,
                  char extra, int padd_start);
int is_printable_custom(char ch);
int append_hex_code_custom(char ch, char buffer[], int index);
int get_string_length_custom(char *str);
long int castToSize(long int number, int size);

#endif /* MAIN_H */

