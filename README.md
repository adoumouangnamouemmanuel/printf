# Custom Printf Project

This project implements a custom printf function in C. It provides functionality similar to the standard printf function with support for various conversion specifiers and flags.

## Description

The custom printf function, `_printf`, accepts a format string and optional arguments. It parses the format string and performs the specified conversions, printing the formatted output to the standard output stream. The implementation handles various conversion specifiers, including `c`, `s`, `%`, `d`, `i`, `u`, `o`, `x`, `X`, `p`, `S`, `b`, `r`, and `R`.

The project includes a `main.h` header file that contains the function prototypes and necessary includes. The function implementations are divided into multiple source files to maintain modularity and adhere to the given requirements. The code follows the Betty style guidelines and has been tested on Ubuntu 20.04 LTS using gcc.

## Project Structure

The project consists of the following files:

- `main.c`: Contains the main function and example usage of the custom printf function.
- `main.h`: Header file with function prototypes and necessary includes.
- `helpers.c`: Contains helper functions used by the custom printf function.
- `conversion.c`: Contains conversion functions for different conversion specifiers.
- `modifiers.c`: Contains functions to handle length modifiers, field width, precision, and flag characters.

## Usage

To use the custom printf function in your C project, follow these steps:

1. Include the `main.h` header file in your source file: `#include "main.h"`.
2. Call the `_printf` function, passing the format string and any additional arguments as needed.

Example usage:

```c
#include "main.h"

int main(void) {
    int number = 42;
    char character = 'A';
    char *string = "Hello, world!";

    _printf("Number: %d\n", number);
    _printf("Character: %c\n", character);
    _printf("String: %s\n", string);

    return 0;
}

Compilation
To compile the project, use the following command:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o custom_printf


This command compiles all the source files (*.c) and creates an executable named custom_printf.

Testing
You can test the custom printf function by running the compiled executable. The main.c file provides an example usage of the custom printf function. You can modify and extend it as needed for further testing.

