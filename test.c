#include "get_next_line.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int	fd;

	fd = open("tests/big_line_no_nl", O_RDONLY);

	char *line = get_next_line(fd);
	printf("%zu\n", ft_strlen(line));
	printf(":%s:", line);
	free(line);
	// printf(":%s:", get_next_line(fd));
	// printf(":%s:", get_next_line(fd));
}