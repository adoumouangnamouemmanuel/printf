#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmat - Struct format
 *
 * @fmat: The format.
 * @fn: The function associated.
 */
struct fmat
{
	char fmat;
	int (*fn)(va_list, char[], int, int, int, int);
};

typedef struct fmat fmat_t;

int _printf(const char *format, ...);
int handle_print(const char *fmat, int *ind, va_list args, char buffer[],
	int flags, int width, int precision, int size);

int print_ch(va_list args, char buffer[],
		int flags, int width, int precision, int size);
int print_string(va_list args, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list args, char buffer[],
		int flags, int width, int precision, int size);

int print_int(va_list args, char buffer[],
		int flags, int width, int precision, int size);
int print_binary(va_list args, char buffer[],
		int flags, int width, int precision, int size);
int print_unsigned(va_list args, char buffer[],
		int flags, int width, int precision, int size);
int print_octal(va_list args, char buffer[],
		int flags, int width, int precision, int size);
int print_hexadecimal(va_list args, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa_upper(va_list args, char buffer[],
		int flags, int width, int precision, int size);
int print_hex(va_list args, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size);

int print_non_printable(va_list args, char buffer[],
		int flags, int width, int precision, int size);

int print_pointer(va_list args, char buffer[],
		int flags, int width, int precision, int size);
int get_active_flags(const char *format, int *index);

int calculate_width(const char *format, int *index, va_list args);
int calculate_precision(const char *format, int *index, va_list args);
int calculate_cast_size(const char *format, int *index);

int print_reverse(va_list args, char buffer[], int flags,
		int width, int precision, int size);
int print_rot13string(va_list args, char buffer[],
		int flags, int width, int precision, int size);

int handle_write_char(char ch, char buff[], int flgs,
		int wdth, int prec, int sz);
int write_number(int is_neg, int index, char buff[], int flgs,
		int wdth, int prec, int sz);
int write_num(int index, char buff[], int flgs, int wdth,
		int prec, int length, char padding, char extra_char);
int write_unsigned(int is_neg, int index, char buff[],
		int flgs, int wdth, int prec, int sz);
int write_memory_address(char buff[], int index, int length, int wdth,
		int flgs, char padding, char extra_char, int padd_start);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);

#endif /* MAIN_H */
