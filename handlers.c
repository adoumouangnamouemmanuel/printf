#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @fmat: Formatted string in which to print the arguments.
 * @args: arguments list.
 * @ind: index
 * @buffer: Buffer array to handle print.
 * @flags: Calculates flags
 * @width: get width of arg
 * @precision: Precision spec
 * @size: Size of specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fmat, int *ind, va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, no_len = 0, printed_ch = -1;
	fmat_t fmat_types[] = {
		{'c', print_ch}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmat_types[i].fmat != '\0'; i++)
		if (fmat[*ind] == fmat_types[i].fmat)
			return (fmat_types[i].fn(args, buffer, flags, width, precision, size));

	if (fmat_types[i].fmat == '\0')
	{
		if (fmat[*ind] == '\0')
			return (-1);
		no_len += write(1, "%%", 1);
		if (fmat[*ind - 1] == ' ')
			no_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmat[*ind] != ' ' && fmat[*ind] != '%')
				--(*ind);
			if (fmat[*ind] == ' ')
				--(*ind);
			return (1);
		}
		no_len += write(1, &fmat[*ind], 1);
		return (no_len);
	}
	return (printed_ch);
}
