/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/20 15:36:20 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/20 15:36:20 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("tests/big_line_no_nl", O_RDONLY);
	line = get_next_line(fd);
	printf("%zu\n", ft_strlen(line));
	printf(":%s:", line);
	free(line);
}
