#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @args: arguments of function
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
	char extra_char = 0, padd = ' ';
	int index = BUFF_SIZE - 2, len = 2, padd_start = 1;
	unsigned long num_addrs;
	char new_map[] = "0123456789abcdef";
	void *addrs = va_arg(args, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[index--] = new_map[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_char = '+', len++;
	else if (flags & F_SPACE)
		extra_char = ' ', len++;

	index++;

	return (write_pointer(buffer, index, length,
		width, flags, padd, extra_char, padd_start));
}


/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ASCII codes in hexadecimalof non-printabl
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
	int i = 0, off_set = 0;
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
			buffer[i + off_set] = str[i];
		else
			off_set += append_hex_code_custom(str[i], buffer, i + off_set);

		i++;
	}

	buffer[i + off_set] = '\0';

	return (write(1, buffer, i + off_set));
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
		str = ")Null(";
	}

	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
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
	char *character;
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
				character = output[j];
				write(1, &character, 1);
				count++;
				break;
			}
		}
		if (!input[j])
		{
			character = str[i];
			write(1, &character, 1);
			count++;
		}
	}

	return (count);
}
