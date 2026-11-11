*This activity has been created as part of the 42 curriculum by mghuzlan.*

# ft_printf

## Description

ft_printf is a C library that reproduces a subset of the standard
printf function. Its goal is to develop an understanding of variadic
functions, formatted output, number conversion, and static libraries.

The library provides:

    int ft_printf(const char *format, ...);

Supported conversions:

| Conversion | Output |
|------------|--------|
| %c | A character |
| %s | A null-terminated string |
| %p | A pointer address |
| %d | A signed decimal integer |
| %i | A signed decimal integer |
| %u | An unsigned decimal integer |
| %x | Lowercase hexadecimal |
| %X | Uppercase hexadecimal |
| %% | A literal percent sign |

The function returns the number of bytes printed on successful output.
It does not implement the buffering system of the original printf.

## Instructions

### Compilation

Run the following command from the repository root:

    make

This creates libftprintf.a using ar.

Available Makefile targets:

| Command | Action |
|---------|--------|
| make or make all | Build the library |
| make clean | Remove object files |
| make fclean | Remove object files and the library |
| make re | Clean and rebuild the library |

Compilation uses cc with -Wall -Wextra -Werror.

### Usage

Include the project header in your program:

    #include "ft_printf.h"

Example:

    int main(void)
    {
        ft_printf("Hello, %s! Number: %d\n", "world", 42);
        return (0);
    }

Save your program as main.c and compile it with the library:

    cc -Wall -Wextra -Werror main.c libftprintf.a -o example

Run it:

    ./example

Expected output:

    Hello, world! Number: 42

## Algorithm and Data Structures

### Format-string traversal

The format string is processed from left to right using an index.

Ordinary characters are written directly. When a percent sign is
encountered, the following character selects the conversion. A
dispatch helper calls the corresponding printing function.

The format index tracks the position in the input string. A separate
counter tracks the number of bytes printed. Keeping these values
separate avoids counting format instructions such as %d as output.

This approach is straightforward and processes the format string
without creating an intermediate formatted string.

### Variadic arguments

A va_list tracks access to the additional arguments.

va_start initializes argument access, and va_arg retrieves values
using the type required by each conversion. va_end finishes access
before the function returns.

For example, %c retrieves an int because character arguments undergo
integer promotion, while %s retrieves a char pointer.

The format string determines which arguments to retrieve; va_list
does not automatically provide their number or types.

### Number conversion

Decimal conversion uses base 10, while hexadecimal conversion uses
base 16.

Remainder extracts the least significant digit, and integer division
removes that digit. For hexadecimal output, a lookup string maps
values 0 through 15 to the corresponding character:

    0123456789abcdef

Uppercase conversion uses:

    0123456789ABCDEF

The hexadecimal helpers store extracted digits in a local character
array and then print them in reverse order. This is necessary because
repeated division produces digits from right to left.

A local array provides simple temporary storage without requiring
dynamic allocation. Its capacity must be sufficient for the supported
integer type.

Zero requires explicit handling so that it prints one digit instead
of producing empty output. Signed decimal output also includes a
minus sign for negative values. Unsigned output preserves the
unsigned type to support values above INT_MAX.

### Pointer output

Pointer addresses are represented using lowercase hexadecimal with
a 0x prefix for non-null pointers.

The address must be preserved in a type wide enough for a pointer;
converting it to unsigned int can truncate it on a 64-bit system.

Null pointers are printed as (nil) to match the Linux libc used
during development.

### Complexity

For a format string of length n producing m output bytes, the
approach takes O(n + m) time, assuming individual output operations
have constant overhead.

Numeric conversion uses temporary space proportional to the maximum
number of digits of the supported type. For fixed-width integer
types, this is bounded constant space.

## Testing

The functions were checked against standard-library formatting,
comparing both the exact output bytes and returned counts.

Tests included:

- Zero and empty strings.
- Signed integer limits and unsigned maximum values.
- Decimal and hexadecimal digit boundaries.
- Lowercase and uppercase hexadecimal output.
- Embedded null characters with %c.
- Null pointers and valid pointer addresses.
- Mixed conversions and repeated calls.
- Long strings and generated numeric inputs.

The combined ft_printf tester passed 1,058 cases during development.
These tests did not simulate write failures or establish correctness
for every possible input.

## Resources

- GNU C Library: Formatted Output
  https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html

- GNU C: Variadic Functions
  https://www.gnu.org/software/c-intro-and-ref/manual/html_node/Variable-Number-of-Arguments.html

- POSIX: write
  https://pubs.opengroup.org/onlinepubs/9799919799/functions/write.html

- GNU Make Manual
  https://www.gnu.org/software/make/manual/

- GNU ar Documentation
  https://sourceware.org/binutils/docs/binutils/ar.html

### AI Usage

ChatGPT was used as a learning and debugging assistant to explain
variadic arguments, headers, object files, linking, and Makefiles.

It also helped interpret compiler errors and test failures, suggested
targeted corrections, generated test harnesses for output and return
counts, and provided a Makefile and README draft.

The test harnesses and their standard-library calls are development
tools and are not part of the submitted library implementation.