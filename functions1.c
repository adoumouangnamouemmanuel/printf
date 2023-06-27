#include "main.h"

/************************* PRINT CHARACTER *************************/

/**
 * print_char_custom - Prints a character
 * @args: Variable arguments list
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_char_custom(va_list args, char buffer[],
                      int flags, int width, int precision, int size)
{
    char c = va_arg(args, int);
    int printed_chars = 0;

    if (!(flags & F_MINUS))
        printed_chars += handle_width_custom(width - 1, ' ');

    printed_chars += handle_write_char_custom(c, buffer, flags, 0, 0, size);

    if (flags & F_MINUS)
        printed_chars += handle_width_custom(width - 1, ' ');

    return (printed_chars);
}

/************************* PRINT STRING *************************/

/**
 * print_string_custom - Prints a string
 * @args: Variable arguments list
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_string_custom(va_list args, char buffer[],
                        int flags, int width, int precision, int size)
{
    char *str = va_arg(args, char *);
    int printed_chars = 0;

    if (str == NULL)
        str = "(null)";

    if (precision >= 0 && precision < (int)str_length_custom(str))
        str = str_n_copy_custom(str, precision);

    if (!(flags & F_MINUS))
        printed_chars += handle_width_custom(width - str_length_custom(str), ' ');

    printed_chars += handle_write_string_custom(str, buffer);

    if (flags & F_MINUS)
        printed_chars += handle_width_custom(width - str_length_custom(str), ' ');

    return (printed_chars);
}

/************************* PRINT PERCENT SIGN *************************/

/**
 * print_percent_custom - Prints a percent sign
 * @args: Variable arguments list
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_percent_custom(va_list args, char buffer[],
                         int flags, int width, int precision, int size)
{
    UNUSED(args);
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    return (handle_write_char_custom('%', buffer, flags, width, precision, size));
}

/************************* PRINT INTEGER *************************/

/**
 * print_int_custom - Prints an integer
 * @args: Variable arguments list
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_int_custom(va_list args, char buffer[],
                     int flags, int width, int precision, int size)
{
    long int num = va_arg(args, long int);
    int printed_chars = 0;
    int is_negative = 0;

    if (num < 0)
    {
        num *= -1;
        is_negative = 1;
    }

    printed_chars += handle_write_integer_custom(num, 10, is_negative,
                                                 buffer, flags, width, precision, size);

    return (printed_chars);
}

/************************* PRINT BINARY *************************/

/**
 * print_binary_custom - Prints a binary number
 * @args: Variable arguments list
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_binary_custom(va_list args, char buffer[],
                        int flags, int width, int precision, int size)
{
    unsigned int num = va_arg(args, unsigned int);
    int printed_chars = 0;
    int binary_length = get_binary_length_custom(num);

    if (precision > binary_length)
        precision = binary_length;

    if (!(flags & F_MINUS))
        printed_chars += handle_width_custom(width - precision, '0');

    printed_chars += handle_write_binary_custom(num, precision, buffer);

    if (flags & F_MINUS)
        printed_chars += handle_width_custom(width - precision, ' ');

    return (printed_chars);
}
