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

### Character checks and conversions

- `ft_isalpha`
- `ft_isdigit`
- `ft_isalnum`
- `ft_isascii`
- `ft_isprint`
- `ft_toupper`
- `ft_tolower`

### String functions

- `ft_strlen`
- `ft_strlcpy`
- `ft_strlcat`
- `ft_strchr`
- `ft_strrchr`
- `ft_strncmp`
- `ft_strnstr`
- `ft_strdup`

### Memory functions

- `ft_memset`
- `ft_bzero`
- `ft_memcpy`
- `ft_memmove`
- `ft_memchr`
- `ft_memcmp`
- `ft_calloc`

### Conversion and string utilities

- `ft_atoi`
- `ft_substr`
- `ft_strjoin`
- `ft_strtrim`
- `ft_split`
- `ft_itoa`
- `ft_strmapi`
- `ft_striteri`

### File descriptor output

- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`

### Linked list functions

The library defines the following singly linked list structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

### Functions for working with linked lists:

- `ft_lstnew`
- `ft_lstadd_front`
- `ft_lstsize`
- `ft_lstlast`
- `ft_lstadd_back`
- `ft_lstdelone`
- `ft_lstclear`
- `ft_lstiter`
- `ft_lstmap`

## Instructions
wip

## Resources
wip