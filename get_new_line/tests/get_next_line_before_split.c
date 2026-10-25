#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*buffer;
	char		*temp;
	char		*line;
	char		*rest;
	ssize_t		bytes_read;
	size_t		i;
	size_t		j;

	// Check the file descriptor and buffer size
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}

	// Allocate memory for reading BUFFER_SIZE bytes
	// Extra byte is needed for '\0'
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}

	// Start reading until we find '\n' or reach EOF
	bytes_read = 1;
	while (bytes_read > 0)
	{
		// Stop if saved already contains a complete line
		if (saved && ft_strchr(saved, '\n'))
			break ;

		// Read the next block from the file
		bytes_read = read(fd, buffer, BUFFER_SIZE);

		// Stop on EOF (0) or error (-1)
		if (bytes_read <= 0)
			break ;

		// Terminate the buffer as a C string
		buffer[bytes_read] = '\0';

		// Append new data to previously saved data
		if (saved)
			temp = ft_strjoin(saved, buffer);
		else
			temp = ft_strjoin("", buffer);

		// Free the old saved string
		// Keep the newly allocated string
		free(saved);
		saved = temp;

		// Stop if memory allocation failed
		if (!saved)
			break ;
	}

	// Reading is finished, so the temporary buffer is no longer needed
	free(buffer);

	// Handle read errors or missing saved data
	if (bytes_read < 0 || !saved)
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}

	// Find the end of the first line
	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;

	// Include '\n' in the returned line if it exists
	if (saved[i] == '\n')
		i++;

	// Allocate memory for the line and '\0'
	line = malloc(i + 1);
	if (!line)
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}

	// Copy the first line from saved into line
	j = 0;
	while (j < i)
	{
		line[j] = saved[j];
		j++;
	}

	// Terminate the returned line
	line[j] = '\0';

	// Check if there is any data left after the first line
	if (saved[i] == '\0')
		rest = NULL;
	else
	{
		// Copy the remaining data into new memory
		rest = ft_strjoin("", saved + i);
	}

	// Handle memory allocation failure for the remainder
	if (saved[i] != '\0' && !rest)
	{
		free(line);
		free(saved);
		saved = NULL;
		return (NULL);
	}

	// Free the old saved data
	free(saved);

	// Keep the remaining data for the next function call
	saved = rest;

	// Return exactly one line
	return (line);
}