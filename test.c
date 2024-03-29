#include "include/ft_get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int	fd = open("Makefile", O_RDONLY);
	char	*line;
	
	line = ft_get_next_line(fd);
	while (line)
		line = ft_get_next_line(fd);
	return (0);
}