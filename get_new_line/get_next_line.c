/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abozhek <abozhek@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 20:09:11 by abozhek           #+#    #+#             */
/*   Updated: 2026/11/09 10:54:09 by abozhek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*save_new_data(char *saved, char *buffer)
{
	char	*temp;

	if (saved)
		temp = ft_strjoin(saved, buffer);
	else
		temp = ft_strjoin("", buffer);
	free(saved);
	saved = temp;
	return (saved);
}

/* Read until saved contains '\n' or reading stops. */
static char	*read_buffer(int fd, char *buffer, char *saved)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (saved && ft_strchr(saved, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		saved = save_new_data(saved, buffer);
		if (!saved)
			break ;
	}
	free(buffer);
	if (bytes_read < 0 || !saved)
	{
		free(saved);
		return (NULL);
	}
	return (saved);
}

static char	*read_saved(int fd, char *saved)
{
	char	*buffer;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(saved);
		return (NULL);
	}
	return (read_buffer(fd, buffer, saved));
}

static char	*save_rest_and_return_line(char **saved, char *line)
{
	char	*rest;
	size_t	i;

	i = ft_strlen(line);
	if ((*saved)[i] == '\0')
		rest = NULL;
	else
		rest = ft_strjoin("", *saved + i);
	if ((*saved)[i] != '\0' && !rest)
	{
		free(line);
		free(*saved);
		*saved = NULL;
		return (NULL);
	}
	free(*saved);
	*saved = rest;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}
	saved = read_saved(fd, saved);
	if (!saved)
		return (NULL);
	line = copy_the_first_line(saved);
	if (!line)
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}
	return (save_rest_and_return_line(&saved, line));
}
