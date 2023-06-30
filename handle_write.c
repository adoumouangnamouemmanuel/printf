handle.c

#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_write_char - Prints a character
 * @ch: Character to be printed
 * @buff: Buffer array to handle print
 * @flgs: Calculates active flags
 * @wdth: Width specifier
 * @prec: Precision specifier
 * @sz: Size specifier
 *
 * Return: Number of characters printed
 */
int handle_write_char(char ch, char buff[], int flgs,
		int wdth, int prec, int sz)
{
	int i = 0;
	char padding = ' ';

	UNUSED(prec);
	UNUSED(sz);

	if (flgs & F_ZERO)
		padding = '0';

	buff[i++] = ch;
	buff[i] = '\0';

	if (wdth > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < wdth - 1; i++)
			buff[BUFF_SIZE - i - 2] = padding;

		if (flgs & F_MINUS)
			return (write(1, &buff[0], 1) +
				write(1, &buff[BUFF_SIZE - i - 1], wdth - 1));
		else
			return (write(1, &buff[BUFF_SIZE - i - 1], wdth - 1) +
				write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Prints a number
 * @is_neg: Indicates if the number is negative
 * @index: Index at which the number starts in the buffer
 * @buff: Buffer array to handle print
 * @flgs: Calculates active flags
 * @wdth: Width specifier
 * @prec: Precision specifier
 * @sz: Size specifier
 *
 * Return: Number of characters printed
 */
int write_number(int is_neg, int index, char buff[],
		int flgs, int wdth, int prec, int sz)
{
	int length = BUFF_SIZE - index - 1;
	char padding = ' ', extra_char = 0;

	UNUSED(sz);

	if ((flgs & F_ZERO) && !(flgs & F_MINUS))
		padding = '0';
	if (is_neg)
		extra_char = '-';
	else if (flgs & F_PLUS)
		extra_char = '+';
	else if (flgs & F_SPACE)
		extra_char = ' ';

	return (write_num(index, buff, flgs, wdth,
		prec, length, padding, extra_char));
}

/**
 * write_num - Writes a number using a buffer
 * @index: Index at which the number starts in the buffer
 * @buff: Buffer array
 * @flgs: Flags specifier
 * @wdth: Width specifier
 * @prec: Precision specifier
 * @length: Number length
 * @padding: Padding character
 * @extra_char: Extra character
 *
 * Return: Number of characters printed
 */
int write_num(int index, char buff[], int flgs, int wdth, int prec,
		int length, char padding, char extra_char)
{
	int i, padd_start = 1;

	if (prec == 0 && index == BUFF_SIZE - 2 && buff[index] == '0' && wdth == 0)
		return (0);
	if (prec == 0 && index == BUFF_SIZE - 2 && buff[index] == '0')
		buff[index] = padding = ' ';
	if (prec > 0 && prec < length)
		padding = ' ';
	while (prec > length)
		buff[--index] = '0', length++;
	if (extra_char != 0)
		length++;
	if (wdth > length)
	{
		for (i = 1; i < wdth - length + 1; i++)
			buff[i] = padding;
		buff[i] = '\0';
		if (flgs & F_MINUS && padding == ' ')
		{
			if (extra_char)
				buff[--index] = extra_char;
			return (write(1, &buff[index], length) + write(1, &buff[1], i - 1));
		}
		else if (!(flgs & F_MINUS) && padding == ' ')
		{
			if (extra_char)
				buff[--index] = extra_char;
			return (write(1, &buff[1], i - 1) + write(1, &buff[index], length));
		}
		else if (!(flgs & F_MINUS) && padding == '0')
		{
			if (extra_char)
				buff[--padd_start] = extra_char;
			return (write(1, &buff[padd_start], i - padd_start) +
				write(1, &buff[index], length - (1 - padd_start)));
		}
	}
	if (extra_char)
		buff[--index] = extra_char;
	return (write(1, &buff[index], length));
}

/**
 * write_unsigned - Writes an unsigned number
 * @is_neg: Indicates if the number is negative
 * @index: Index at which the number starts in the buffer
 * @buff: Buffer array
 * @flgs: Flags specifier
 * @wdth: Width specifier
 * @prec: Precision specifier
 * @sz: Size specifier
 *
 * Return: Number of characters printed
 */
int write_unsigned(int is_neg, int index,
	char buff[], int flgs, int wdth, int prec, int sz)
{
	int length = BUFF_SIZE - index - 1, i = 0;
	char padding = ' ';

	UNUSED(is_neg);
	UNUSED(sz);

	if (prec == 0 && index == BUFF_SIZE - 2 && buff[index] == '0')
		return (0);

	if (prec > 0 && prec < length)
		padding = ' ';

	while (prec > length)
	{
		buff[--index] = '0';
		length++;
	}

	if ((flgs & F_ZERO) && !(flgs & F_MINUS))
		padding = '0';

	if (wdth > length)
	{
		for (i = 0; i < wdth - length; i++)
			buff[i] = padding;

		buff[i] = '\0';

		if (flgs & F_MINUS)
		{
			return (write(1, &buff[index], length) + write(1, &buff[0], i));
		}
		else
		{
			return (write(1, &buff[0], i) + write(1, &buff[index], length));
		}
	}

	return (write(1, &buff[index], length));
}

/**
 * write_memory_address - Write a memory address
 * @buff: Buffer array
 * @index: Index at which the number starts in the buffer
 * @length: Length of the number
 * @wdth: Width specifier
 * @flgs: Flags specifier
 * @padding: Char representing the padding
 * @extra_char: Char representing the extra character
 * @padd_start: Index at which the padding should start
 *
 * Return: Number of characters printed
 */
int write_memory_address(char buff[], int index, int length,
	int wdth, int flgs, char padding, char extra_char, int padd_start)
{
	int i;

	if (wdth > length)
	{
		for (i = 3; i < wdth - length + 3; i++)
			buff[i] = padding;
		buff[i] = '\0';
		if (flgs & F_MINUS && padding == ' ')
		{
			buff[--index] = 'x';
			buff[--index] = '0';
			if (extra_char)
				buff[--index] = extra_char;
			return (write(1, &buff[index], length) + write(1, &buff[3], i - 3));
		}
		else if (!(flgs & F_MINUS) && padding == ' ')
		{
			buff[--index] = 'x';
			buff[--index] = '0';
			if (extra_char)
				buff[--index] = extra_char;
			return (write(1, &buff[3], i - 3) + write(1, &buff[index], length));
		}
		else if (!(flgs & F_MINUS) && padding == '0')
		{
			if (extra_char)
				buff[--padd_start] = extra_char;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[padd_start], i - padd_start) +
					write(1, &buff[index], length - (1 - padd_start) - 2));
		}
	}
	buff[--index] = 'x';
	buff[--index] = '0';
	if (extra_char)
		buff[--index] = extra_char;
	return (write(1, &buff[index], BUFF_SIZE - index - 1));
}
