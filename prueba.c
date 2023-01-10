#include "get_next_line.h"

char	*get_next_line(int fd)
{
	
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf ("%s", line);
	free(line);
	close(fd);
	return (0);
}
