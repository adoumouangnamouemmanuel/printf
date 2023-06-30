#include "main.h"

/**
 * get_active_flags - Calculates active flags
 * @format: Format string in which to print the arguments
 * @index: Current index in the format string
 * Return: Active flags
 */
int get_active_flags(const char *format, int *index)
{
	int i, currIndex;
	int flags = 0;
	const char FLAGS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (currIndex = *index + 1; format[currIndex] != '\0'; currIndex++)
	{
		for (i = 0; FLAGS[i] != '\0'; i++)
		{
			if (format[currIndex] == FLAGS[i])
			{
				flags |= FLAGS_VALUES[i];
				break;
			}
		}

		if (FLAGS[i] == '\0')
			break;
	}

	*index = currIndex - 1;

	return (flags);
}
