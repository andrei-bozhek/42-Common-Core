#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*buffer;
	char		*temp;
	ssize_t		bytes_read;

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

	// Next step: extract one line from saved
	// Next step: keep the remaining characters
	return (NULL);
}

#include <stdio.h>

int main(void)
{
	char	*result;

	result = ft_strjoin("Wo", "rld");
	if (!result)
		return (1);
	printf("Result: %s\n", result);
	printf("Test: %s\n", strcmp(result, "World") == 0 ? "OK" : "FAIL");
	free(result);
	return (0);
}