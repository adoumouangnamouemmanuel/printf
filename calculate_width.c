#include "main.h"

/**
 * calculate_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments
 * @index: List of arguments to be printed
 * @args: List of arguments
 *
 * Return: Width
 */
int calculate_width(const char *format, int *index, va_list args)
{
	int curr_index;
	int width = 0;

	for (curr_index = *index + 1; format[curr_index] != '\0'; curr_index++)
	{
		if (is_digit(format[curr_index]))
		{
			width *= 10;
			width += format[curr_index] - '0';
		}
		else if (format[curr_index] == '*')
		{
			curr_index++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*index = curr_index - 1;

	return (width);
}

