calculate_size.c

#include "main.h"

/**
 * calculate_cast_size - Calculates the size to cast the argument
 * @format: Formatted to print the arguments
 * @index: Index of the current character in the format string
 *
 * Return: Size of the cast.
 */
int calculate_cast_size(const char *format, int *index)
{
	int currIndex = *index + 1;
	int castSize = 0;

	if (format[currIndex] == 'l')
		castSize = S_LONG;
	else if (format[currIndex] == 'h')
		castSize = S_SHORT;

	if (castSize == 0)
		*index = currIndex - 1;
	else
		*index = currIndex;

	return (castSize);
}
