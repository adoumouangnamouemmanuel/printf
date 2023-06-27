#include "main.h"

/**
 * handle_argument - Handles the printing of an argument based on its type
 * @format: Formatted string in which to print the arguments
 * @index: Current index position in the format string
 * @args: List of arguments to be printed
 * @buffer: Buffer array to handle printing
 * @active_flags: Active flags
 * @print_width: Width specification
 * @print_precision: Precision specification
 * @cast_size: Size specifier
 *
 * Return: Number of characters printed or -1 on error
 */
int handle_argument(const char *format, int *index, va_list args, char buffer[],
                    int active_flags, int print_width, int print_precision, int cast_size)
{
    int loop_index, length_of_unknown = 0, num_printed_chars = -1;

    struct {
        char format_specifier;
        int (*print_function)(va_list, char[], int, int, int, int);
    } format_types[] = {
        {'c', print_character}, {'s', print_string}, {'%', print_percent},
        {'i', print_integer}, {'d', print_integer}, {'b', print_binary},
        {'u', print_unsigned_integer}, {'o', print_octal}, {'x', print_hexadecimal},
        {'X', print_hexadecimal_upper}, {'p', print_pointer}, {'S', print_non_printable},
        {'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
    };

    for (loop_index = 0; format_types[loop_index].format_specifier != '\0'; loop_index++) {
        if (format[*index] == format_types[loop_index].format_specifier) {
            return (format_types[loop_index].print_function(args, buffer, active_flags, print_width, print_precision, cast_size));
        }
    }

    if (format_types[loop_index].format_specifier == '\0') {
        if (format[*index] == '\0') {
            return (-1);
        }

        length_of_unknown += write(1, "%%", 1);

        if (format[*index - 1] == ' ') {
            length_of_unknown += write(1, " ", 1);
        } else if (print_width) {
            --(*index);
            while (format[*index] != ' ' && format[*index] != '%') {
                --(*index);
            }
            if (format[*index] == ' ') {
                --(*index);
            }
            return (1);
        }

        length_of_unknown += write(1, &format[*index], 1);
        return (length_of_unknown);
    }

    return (num_printed_chars);
}
