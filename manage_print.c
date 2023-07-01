#include "main.h"

/************************* PRINT CHARACTER *************************/

/**
 * print_ch - Prints a character
 * @args: Variable arguments list
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_ch(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(args, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/************************* PRINT STRING *************************/

/**
 * print_string - Prints a string
 * @args: Variable arguments list
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_string(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	int len = 0, i;
	char *str = va_arg(args, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));
}


/************************* PRINT PERCENT SIGN *************************/

/**
 * print_percent - Prints a percent sign
 * @args: Variable arguments list
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_percent(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}

/************************* PRINT INTEGER *************************/

/**
 * print_int - Prints an integer
 * @args: Variable arguments list
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_int(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_neg = 0;
	long int n = va_arg(args, long int);
	unsigned long int nums;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	nums = (unsigned long int)n;

	if (n < 0)
	{
		nums = (unsigned long int)((-1) * n);
		is_neg = 1;
	}

	while (nums > 0)
	{
		buffer[i--] = (nums % 10) + '0';
		nums /= 10;
	}
	i++;

	return (write_number(is_neg, i, buffer, flags, width, precision, size));
}


/************************* PRINT BINARY *************************/

/**
 * print_binary - Prints a binary number
 * @args: Variable arguments list
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_binary(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int j, k, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	j = va_arg(args, unsigned int);
	k = 2147483648; /* (2 ^ 31) */
	a[0] = j / k;
	for (i = 1; i < 32; i++)
	{
		k /= 2;
		a[i] = (j / k) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char x = '0' + a[i];

			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
