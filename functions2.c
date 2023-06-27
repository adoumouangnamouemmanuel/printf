#include "main.h"

#define BUFF_SIZE 1024

/************************* PRINT UNSIGNED NUMBER *************************/

/**
 * print_unsigned - Prints an unsigned number
 * @args: Variable arguments list
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_unsigned(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = convert_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsigned(0, i, buffer, flags, width, precision, size));
}

/************************* PRINT OCTAL NUMBER *************************/

/**
 * print_octal - Prints an unsigned number in octal notation
 * @args: Variable arguments list
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_octal(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsigned(0, i, buffer, flags, width, precision, size));
}

/************************* PRINT HEXADECIMAL NUMBER *************************/

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @args: Variable arguments list
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hex(args, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************************* PRINT UPPER HEXADECIMAL NUMBER *************************/

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @args: Variable arguments list
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexa_upper(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hex(args, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************************* PRINT HEXADECIMAL NUMBER *************************/

/**
 * print_hex - Prints a hexadecimal number
 * @args: Variable arguments list
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @flag_ch: Flag character
 * @width: Width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hex(va_list args, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsigned(0, i, buffer, flags, width, precision, size));
}
