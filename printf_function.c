#include "main.h"

void print_output_buffer(char output_buffer[], int *output_index);

/**
 * new_printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int format_index, result = 0, printed_chars = 0;
	int new_flags, new_width, new_precision, new_size, output_index = 0;
	va_list args;
	char output_buffer[BUFF_SIZE];

	if (new_format == NULL)
		return (-1);

	va_start(args, new_format);
	for (format_index = 0; new_format[format_index] != '\0'; format_index++)
	{
		char current_char = new_format[format_index];

		if (current_char != '%')
		{
			output_buffer[output_index++] = current_char;
			if (output_index == BUFF_SIZE)
				print_output_buffer(output_buffer, &output_index);
			printed_chars++;
		}
		else
		{
			print_output_buffer(output_buffer, &output_index);
			new_flags = get_flags(new_format, &format_index);
			new_width = get_width(new_format, &format_index, args);
			new_precision = get_precision(new_format, &format_index, args);
			new_size = get_size(new_format, &format_index);
			format_index++;
			result = handle_print(new_format, &format_index, args, output_buffer,
					      new_flags, new_width, new_precision, new_size);
			if (result == -1)
				return (-1);
			printed_chars += result;
		}
	}

	print_output_buffer(output_buffer, &output_index);

	va_end(args);

	return (printed_chars);
}

/**
 * print_output_buffer - Prints the contents of the output buffer if it exists
 * @output_buffer: Array of characters
 * @output_index: Index at which to add the next character
 * */
void print_output_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, buffer, *buffer_index);

	*buffer_index = 0;
}
