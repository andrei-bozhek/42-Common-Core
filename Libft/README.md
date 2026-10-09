*This project has been created as part of the 42 curriculum by abozhek.*

# Libft

## Description

Libft is my first library project in the 42 Common Core.

The goal of the project is to implement a reusable C library containing
common functions for memory manipulation, string processing, character
checks, conversions, output, and linked lists.

The project includes reimplementations of several standard C library
functions as well as additional utility functions that will be reused
in future 42 projects.

The library is compiled into:

`libft.a`

## Library Contents

### Character Checks and Conversion

| Function | Description |
|---|---|
| `ft_isalpha` | Checks whether a character is alphabetic. |
| `ft_isdigit` | Checks whether a character is a decimal digit. |
| `ft_isalnum` | Checks whether a character is alphanumeric. |
| `ft_isascii` | Checks whether a value belongs to the ASCII character set. |
| `ft_isprint` | Checks whether a character is printable. |
| `ft_toupper` | Converts a lowercase letter to uppercase. |
| `ft_tolower` | Converts an uppercase letter to lowercase. |

### String Functions

| Function | Description |
|---|---|
| `ft_strlen` | Returns the length of a string. |
| `ft_strlcpy` | Copies a string into a buffer with size limitation. |
| `ft_strlcat` | Appends a string to another buffer with size limitation. |
| `ft_strchr` | Finds the first occurrence of a character in a string. |
| `ft_strrchr` | Finds the last occurrence of a character in a string. |
| `ft_strncmp` | Compares two strings up to a specified number of characters. |
| `ft_strnstr` | Finds a substring within a limited part of a string. |
| `ft_strdup` | Allocates and returns a duplicate of a string. |

### Memory Functions

| Function | Description |
|---|---|
| `ft_memset` | Fills a block of memory with a byte value. |
| `ft_bzero` | Sets a block of memory to zero. |
| `ft_memcpy` | Copies a block of memory to another location. |
| `ft_memmove` | Copies memory safely when source and destination overlap. |
| `ft_memchr` | Searches a memory block for a byte value. |
| `ft_memcmp` | Compares two blocks of memory. |
| `ft_calloc` | Allocates zero-initialized memory. |

### String and Conversion Utilities

| Function | Description |
|---|---|
| `ft_atoi` | Converts the beginning of a string to an integer. |
| `ft_substr` | Allocates and returns a substring. |
| `ft_strjoin` | Allocates and joins two strings. |
| `ft_strtrim` | Removes specified characters from both ends of a string. |
| `ft_split` | Splits a string into a NULL-terminated array of strings. |
| `ft_itoa` | Converts an integer to a newly allocated string. |
| `ft_strmapi` | Applies a function to each character and creates a new string. |
| `ft_striteri` | Applies a function to each character of a string in place. |

### File Descriptor Output

| Function | Description |
|---|---|
| `ft_putchar_fd` | Writes a character to a file descriptor. |
| `ft_putstr_fd` | Writes a string to a file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor. |
| `ft_putnbr_fd` | Writes an integer to a file descriptor. |

### Linked List Functions

The library uses the following singly linked list structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

### Functions for working with linked lists:

| Function | Description |
|---|---|
| `ft_lstnew` | Allocates and initializes a new list node. |
| `ft_lstadd_front` | Adds a node to the beginning of a list. |
| `ft_lstsize` | Counts the number of nodes in a list. |
| `ft_lstlast` | Returns the last node of a list. |
| `ft_lstadd_back` | Adds a node to the end of a list. |
| `ft_lstdelone` | Frees one node and its content using a supplied function. |
| `ft_lstclear` | Frees a node and all following nodes in the list. |
| `ft_lstiter` | Applies a function to the content of every node. |
| `ft_lstmap` | Creates a new list by applying a function to every node's content. |

## Instructions

### Compilation

Run:

```sh
make
```

This compiles the source files with `cc` using `-Wall -Wextra -Werror`
and creates the static library:

```text
libft.a
```

Available Makefile rules:

| Command | Description |
|---|---|
| `make` | Builds `libft.a`. |
| `make clean` | Removes object files. |
| `make fclean` | Removes object files and `libft.a`. |
| `make re` | Rebuilds the library from scratch. |

### Usage

Include the header in your source file:

```c
#include "libft.h"
```

Compile your program and link it with the library:

```sh
cc -Wall -Wextra -Werror main.c libft.a -o program
```

Then run:

```sh
./program
```

## Resources

The following resources were used while working on Libft:

- **Official Libft subject** — project requirements, function prototypes,
  allowed external functions, and expected behavior.
- **Unix manual pages (`man`)** — reference for the original libc functions,
  their return values, edge cases, and expected behavior.
- **C standard library documentation** — additional reference for memory,
  string, character classification, and conversion functions.
- **42 Norm documentation** — coding style and formatting requirements.

Useful manual pages included:

```sh
man 3 strlen
man 3 memset
man 3 memcpy
man 3 memmove
man 3 strchr
man 3 strncmp
man 3 atoi
man 3 calloc
man 3 strdup
man 3 malloc
man 3 free
man 2 write
```

Some BSD-specific functions such as `strlcpy`, `strlcat`, and `strnstr`
may not be available in the default GNU C Library, so their behavior was
also checked against the project subject and BSD-compatible documentation.

### AI Usage

AI tools were used as a learning aid during the project.
They were mainly used to clarify C concepts such as pointers, memory allocation,
function pointers, and linked lists.