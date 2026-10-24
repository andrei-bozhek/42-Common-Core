#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*buffer;
	char		*temp;
	ssize_t		bytes_read;
	char		*line;
	char		*rest;
	size_t		i;
	size_t		j;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (saved && ft_strchr(saved, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		if (saved)
			temp = ft_strjoin(saved, buffer);
		else
			temp = ft_strjoin("", buffer);
		free(saved);
		saved = temp;
		if (!saved)
			break ;
	}
	free(buffer);
	if (bytes_read < 0 || !saved)
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}

	// Extract one line from saved
	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}
	j = 0;
	while (j < i)
	{
		line[j] = saved[j];
		j++;
	}
	line[j] = '\0';

	// Keep the remaining characters
}
