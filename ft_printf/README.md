*This project has been created as part of the 42 curriculum by abozhek.*

# ft_printf

## Description

ft_printf is a library project in the 42 Common Core.

The goal of the project is to recreate a subset of the standard C `printf()`
function while learning how to handle a variable number of arguments.
The implementation writes formatted output to standard output and returns
the number of bytes written, or `-1` if an output error occurs.

The library is compiled into:

`libftprintf.a`

The function prototype is:

```c
int ft_printf(const char *format, ...);
```

## Supported Conversions

| Conversion | Description |
|---|---|
| `%c` | Prints a single character, including a null character. |
| `%s` | Prints a null-terminated string. |
| `%p` | Prints a pointer in hexadecimal with the `0x` prefix. |
| `%d` | Prints a signed decimal integer. |
| `%i` | Prints a signed decimal integer. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` | Prints an unsigned integer in lowercase hexadecimal. |
| `%X` | Prints an unsigned integer in uppercase hexadecimal. |
| `%%` | Prints a percent sign without consuming an argument. |

This implementation prints `(null)` for a null string pointer and `(nil)`
for a null pointer passed to `%p`, matching the Linux behavior used for testing.

The project implements the mandatory conversions. Bonus flags, field width,
and precision are not implemented.

## Instructions

### Compilation

Run the following commands from the `ft_printf` directory. A C compiler,
`make`, and `ar` are required.

```sh
make
```

This compiles the source files with `cc` using `-Wall -Wextra -Werror`
and creates the static library:

```text
libftprintf.a
```

Available Makefile rules:

| Command | Description |
|---|---|
| `make` | Builds `libftprintf.a`. |
| `make clean` | Removes object files. |
| `make fclean` | Removes object files and `libftprintf.a`. |
| `make re` | Rebuilds the library from scratch. |

### Usage

Include the header in your source file:

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello %s! Number: %d, hex: %x\n", "42", 123, 255U);
    if (count == -1)
        return (1);
    ft_printf("Bytes written: %d\n", count);
    return (0);
}
```

Save the example as `main.c`, compile it, and link it with the library:

```sh
cc -Wall -Wextra -Werror main.c libftprintf.a -o program
```

Then run:

```sh
./program
```

## Algorithm and Data Structures

### Format Parsing

The format string is scanned once from left to right. Ordinary characters
are written directly. When a percent sign is followed by a conversion
character, a dispatcher selects the corresponding output function.

`va_start` initializes argument traversal, `va_arg` retrieves each value
with the type expected by its conversion, and `va_end` finishes traversal.
The dispatcher receives a pointer to the `va_list` so that argument traversal
advances consistently across successive conversions.

Each output function returns its number of written bytes or `-1` on failure.
The parser adds successful results to a running total and stops immediately
on an error. A null character printed through `%c` still counts as one byte.

### Number Conversion

Numbers are printed recursively. Division by the base processes the preceding
digits first, and the remainder selects the current digit. Decimal output uses
base 10; hexadecimal output uses base 16 and a digit string that determines
the letter case. Zero is printed as a single digit.

Signed decimal output converts the input to `long` before negating negative
values. On the target Linux platform, where `long` is wider than `int`, this
allows `INT_MIN` to be handled without overflowing an `int`.
Non-null pointers are converted to `unsigned long` and printed in lowercase
hexadecimal after the `0x` prefix on this platform.

### Design Choices

The implementation uses the format string, a `va_list`, scalar counters,
and constant digit strings. No heap allocation or additional container is needed
because each argument is processed and printed immediately. This also avoids
implementing the buffering used by the original `printf()`.

The code is divided by responsibility:

| File | Responsibility |
|---|---|
| `ft_printf.c` | Variadic argument setup, format parsing, and conversion dispatch. |
| `ft_print_common.c` | Character, string, and decimal output. |
| `ft_print_base.c` | Hexadecimal and pointer output. |
| `ft_printf.h` | Shared declarations and required headers. |

## Resources

- **Official ft_printf subject** — required conversions,
  allowed external functions, submission requirements, and bonus scope.
- **Unix manual pages (`man`)** — references for formatted output,
  variadic arguments, output errors, and static libraries.
- **42 Norm documentation and Norminette** — coding style and formatting
  requirements.

Useful manual pages:

```sh
man 3 printf
man 3 stdarg
man 2 write
man 1 ar
man 1 make
```

### AI Usage

AI tools were used as a learning aid during the project.
