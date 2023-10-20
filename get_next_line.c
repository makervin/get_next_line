/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/20 15:20:30 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/20 15:20:30 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <unistd.h>
#include <stdio.h>

#define MAX_FD	1024

char	*create_line(int nl_position, char **buffer)
{
	char	*res;
	char	*tmp;

	if (nl_position == 0)
	{
		if (**buffer == '\0')
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		res = *buffer;
		*buffer = NULL;
		return (res);
	}
	res = ft_substr(*buffer, 0, nl_position);
	tmp = *buffer;
	*buffer = ft_substr(*buffer, nl_position, BUFFER_SIZE);
	free(tmp);
	return (res);
}

char	*read_line(int fd, char **buffer, char *read_buffer)
{
	ssize_t	bytes_read;
	char	*nl;
	char	*tmp;

	nl = ft_strchr(*buffer, '\n');
	while (nl == NULL)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (create_line(0, buffer));
		read_buffer[bytes_read] = '\0';
		tmp = *buffer;
		*buffer = ft_strjoin(*buffer, read_buffer);
		free(tmp);
		nl = ft_strchr(*buffer, '\n');
	}
	return (create_line(nl - *buffer + 1, buffer));
}

char	*get_next_line(int fd)
{
	static char	*buffers[MAX_FD + 1] = {NULL};
	char		*line;
	char		*read_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	read_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffers[fd] == NULL)
		buffers[fd] = ft_strdup("");
	line = read_line(fd, &buffers[fd], read_buffer);
	free(read_buffer);
	read_buffer = (NULL);
	return (line);
}
