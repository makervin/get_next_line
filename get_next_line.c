#include "get_next_line.h"

#include <unistd.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 24
#endif

#define MAX_FD	1024

char *process_line(int nl_position, char **buffer)
{
	char	*res;

	res = ft_substr(*buffer, 0, nl_position);
	*buffer = ft_substr(*buffer, nl_position, BUFFER_SIZE);
	return (res);
}

char	*read_line(int fd, char **buffer)
{
	ssize_t	bytes_read;
	char	*nl;
	char	*read_buffer;

	nl = ft_strchr(*buffer, '\n');
	read_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (nl == NULL)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (*buffer);
		*buffer = ft_strjoin(*buffer, read_buffer);
		nl = ft_strchr(*buffer, '\n');
	}
	return (process_line(nl - *buffer + 1, buffer));
}

char *get_next_line(int fd)
{
	static char	*buffers[MAX_FD] = { NULL };
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	if (buffers[fd] == NULL)
		buffers[fd] = ft_strdup("");
	line = read_line(fd, &buffers[fd]);
	return (line);
}