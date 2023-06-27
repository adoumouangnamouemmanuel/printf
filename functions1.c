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

