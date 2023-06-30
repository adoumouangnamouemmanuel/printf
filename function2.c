#include "main.h"

#define BUFF_SIZE 1024

/************************* PRINT UNSIGNED NUMBER *************************/

/**
 * print_unsigned - Prints an unsigned number
 * @args: Variable arguments list
 * @buffer: Buffer array for print
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
	unsigned int nums = va_arg(args, unsigned int);

	nums = convert_size_unsigned(nums, size);

	if (nums == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (nums > 0)
	{
		buffer[i--] = (nums % 10) + '0';
		nums /= 10;
	}
	i++;

	return (write_unsigned(0, i, buffer, flags, width, precision, size));
}

/************************* PRINT OCTAL NUMBER *************************/

/**
 * print_octal - Prints an unsigned number in octal
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
	unsigned int nums = va_arg(args, unsigned int);
	unsigned int init_num = nums;

	UNUSED(width);

	nums = convert_size_unsigned(nums, size);

	if (nums == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (nums > 0)
	{
		buffer[i--] = (nums % 8) + '0';
		nums /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsigned(0, i, buffer, flags, width, precision, size));
}

/************************* PRINT HEXADECIMAL NUMBER *************************/

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal
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
 * print_hex - Prints a hexadecimal number in both upper or lower
 * @args: Variable arguments list
 * @map_to: Array of values to map the number
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @flag_ch: Flag character
 * @width: Width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hex(va_list args, char new_map[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned int nums = va_arg(args, unsigned int);
	unsigned int init_num = nums;

	UNUSED(width);

	nums = convert_size_unsigned(nums, size);

	if (nums == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (nums > 0)
	{
		buffer[i--] = new_map[nums % 16];
		nums /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsigned(0, i, buffer, flags, width, precision, size));
}
