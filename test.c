#include "get_next_line.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int	fd;

	fd = open("tests/01", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}