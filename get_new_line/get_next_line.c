#include "get_next_line.h"

char*	get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return(line);
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