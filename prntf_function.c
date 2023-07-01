#include "main.h"

void print_buffer(char buffer[], int *index);

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int j, result = 0, printed_chars = 0;
	int new_flags, new_width, new_precision, new_size, index = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[index++] = format[j];
			if (index == BUFF_SIZE)
				print_buffer(buffer, &index);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &index);
			new_flags = get_active_flags(format, &j);
			new_width = calculate_width(format, &j, args);
			new_precision = calculate_precision(format, &j, args);
			new_size = calculate_cast_size(format, &j);
			j++;
			result = handle_print(format, &j, args, buffer,
					      new_flags, new_width, new_precision, new_size);
			if (result == -1)
				return (-1);
			printed_chars += result;
		}
	}

	print_buffer(buffer, &index);

	va_end(args);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the output buffer if it exists
 * @buffer: Array of characters
 * @buffer_index: Index at which to add the next character
 */
void print_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}
