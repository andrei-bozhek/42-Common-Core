*This project has been created as part of the 42 curriculum by abozhek.*

English | [日本語](README.ja.md)

# get_next_line

## Description

get_next_line is a project in the 42 Common Core about reading from a file
descriptor one line at a time.

The goal is to implement a function that returns the next line on each call,
using only `read`, `malloc`, and `free` as external functions.
The project introduces static variables, buffered reading, and memory management
across multiple function calls.

```c
char	*get_next_line(int fd);
```

The returned line includes the terminating `\n` when one is present.
The final line is returned even if the file does not end with `\n`.
The function returns `NULL` when there is nothing left to read or an error occurs.
Each returned line must be freed by the caller.

This implementation covers the mandatory part. It keeps one saved string and
does not support alternating between multiple file descriptors.

## Project Contents

| File | Description |
|---|---|
| `get_next_line.c` | Reading, saved data management, and the main function. |
| `get_next_line_utils.c` | String helpers and copying the first line. |
| `get_next_line.h` | Function prototypes, includes, and the default buffer size. |

### Functions

| Function | Description |
|---|---|
| `get_next_line` | Checks arguments and coordinates reading and line extraction. |
| `read_saved` | Allocates the temporary reading buffer. |
| `read_buffer` | Reads until a newline, EOF, or an error is encountered. |
| `save_new_data` | Appends a block to the saved data and frees the old string. |
| `copy_the_first_line` | Allocates and copies the first line from the saved data. |
| `save_rest_and_return_line` | Keeps the remainder for the next call and returns the line. |
| `ft_strlen` | Returns the length of a string. |
| `ft_strchr` | Finds a character in a string. |
| `ft_strjoin` | Allocates and joins two strings. |

## Algorithm

The function keeps unread data in a static pointer named `saved`.
Its value is preserved between calls.

1. Check the file descriptor and buffer size.
2. Allocate a temporary buffer of `BUFFER_SIZE + 1` bytes.
3. If `saved` already contains `\n`, skip reading. Otherwise, read blocks and
   append them to `saved` until a newline is found or EOF is reached.
4. Allocate and copy the first line, including `\n` when present.
5. Copy the remaining data into a separate allocation, free the old `saved`,
   and keep the remainder for the next call.
6. Return the line to the caller.

This approach separates the size of each read from the length of a line.
A line can span several reads, and one read can contain several lines.
Keeping the remainder prevents already-read data from being lost.

The algorithm was chosen for its straightforward use of C strings and explicit
memory ownership. It reads as needed rather than loading the entire file before
returning a line. The temporary buffer is freed after reading, and saved data is
freed when replaced or when an error occurs.

The tradeoff is repeated allocation and copying while assembling a long line.
With a small fixed buffer size, this can lead to quadratic time in the line
length.

## Instructions

### Compilation

No Makefile is required. Compile the two source files together with your program.
Run the following commands from the directory containing `get_next_line.c`.

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
    main.c get_next_line.c get_next_line_utils.c -o program
```

`BUFFER_SIZE` sets the maximum number of bytes requested by each `read` call.
If the flag is omitted, the header defines a default value of `42`.
Use a positive value, for example `1`, `42`, or `1024`.

### Usage

Save this example as `main.c` and compile it using the command above.
Pass a filename to open it directly, or run the program without arguments
to read from standard input.

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc > 2)
		return (1);
	fd = STDIN_FILENO;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("get_next_line returned: %s", line);
		free(line);
		line = get_next_line(fd);
	}
	if (argc == 2)
		close(fd);
	return (0);
}
```

Read a file by name:

```sh
./program input.txt
```

Read from standard input:

```sh
printf 'first\nsecond\n' | ./program
./program < input.txt
```

The first call to `get_next_line` fetches a line before the loop checks it.
Each iteration prints and frees the current line, then fetches the next one.
The loop stops when `get_next_line` returns `NULL`. The program closes the file
if it opened one.

## Resources

- **Official get_next_line subject** — required behavior, allowed external
  functions, buffer size, and submission requirements.
- **Unix manual pages (`man`)** — reading from file descriptors, allocation,
  and releasing memory.
- **42 Norm documentation** — coding style and formatting requirements.

Useful manual pages:

```sh
man 2 read
man 2 open
man 2 close
man 3 malloc
man 3 free
```

### AI Usage

AI tools were used as a learning aid to explain pointers, static variables,
memory ownership, and error handling. 
