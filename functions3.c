#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Flag options
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_pointer(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_char = 0, padding = ' ';
	int index = BUFFER_SIZE - 2, length = 2; /* length = 2 for '0x' */
	unsigned long int address;
	char hex_map[] = "0123456789abcdef";
	void *pointer = va_arg(args, void *);

	UNUSED(width);
	UNUSED(size);

	if (pointer == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFER_SIZE - 1] = '\0';
	UNUSED(precision);

	address = (unsigned long int)pointer;

	while (address > 0)
	{
		buffer[index--] = hex_map[address % 16];
		address /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (flags & F_PLUS)
		extra_char = '+', length++;
	else if (flags & F_SPACE)
		extra_char = ' ', length++;

	index++;

	return (write_pointer(buffer, index, length,
		width, flags, padding, extra_char));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ASCII codes in hexadecimal of non-printable characters
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Flag options
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_non_printable(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(args, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable_custom(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hex_code_custom(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints a string in reverse order
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Flag options
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_reverse(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(args, char *);

	if (str == NULL)
	{
		UNUSED(precision);
		str = "(Null)";
	}

	count = get_string_length_custom(str);

	while (count > 0)
	{
		char character = str[count - 1];
		write(1, &character, 1);
		count--;
	}

	return (get_string_length_custom(str));
}

/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Prints a string in ROT13 encoding
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Flag options
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_rot13string(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	unsigned int i, j;
	int count = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; input[j]; j++)
		{
			if (input[j] == str[i])
			{
				char character = output[j];
				write(1, &character, 1);
				count++;
				break;
			}
		}
		if (!input[j])
		{
			char character = str[i];
			write(1, &character, 1);
			count++;
		}
	}

	return (count);
}

