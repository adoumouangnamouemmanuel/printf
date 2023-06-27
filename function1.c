#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: Format string containing zero or more directives.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	printed_chars = _print_format(format, args);

	va_end(args);

	return (printed_chars);
}

/**
 * _print_format - Prints the formatted output.
 * @format: Format string containing zero or more directives.
 * @args: List of arguments to be formatted.
 *
 * Return: Number of characters printed.
 */
int _print_format(const char *format, va_list args)
{
	int printed_chars = 0;
	char current_char;

	while (*format)
	{
		current_char = *format;

		if (current_char == '%')
		{
			format++;

			if (*format == '\0')
				return (-1);

			switch (*format)
			{
			case 'c':
				printed_chars += _putchar(va_arg(args, int));
				break;
			case 's':
				printed_chars += _print_string(va_arg(args, char *));
				break;
			case '%':
				printed_chars += _putchar('%');
				break;
			default:
				printed_chars += _putchar('%');
				printed_chars += _putchar(*format);
				break;
			}
		}
		else
		{
			printed_chars += _putchar(current_char);
		}

		format++;
	}

	return (printed_chars);
}
/**
 * _putchar - Writes a character to stdout.
 * @c: The character to be written.
 *
 * Return: On success (1), on error (-1).
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _print_string - Prints a string to stdout.
 * @str: The string to be printed.
 *
 * Return: Number of characters printed.
 */
int _print_string(char *str)
{
	int printed_chars = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		printed_chars += _putchar(*str);
		str++;
	}

	return (printed_chars);
}
