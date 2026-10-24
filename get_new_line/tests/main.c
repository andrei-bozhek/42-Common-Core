#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>

// int main(void)
// {
// 	char	*result;

// 	result = ft_strjoin("Wo", "rld");
// 	if (!result)
// 		return (1);
// 	printf("Result: %s\n", result);
// 	printf("Test: %s\n", strcmp(result, "World") == 0 ? "OK" : "FAIL");
// 	free(result);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}