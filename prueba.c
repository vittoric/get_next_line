#include "get_next_line.h"
#include <string.h> 

char	*get_next_line(int fd)
{
	int		to_read;
	char	*p;
	static char	*alocate;
	 char	*newline_ptr;
	 static int		current_position = 0;

	alocate = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (alocate == NULL)
	{
		return (NULL);
	}

	to_read = 1;
	while (to_read > 0)
	{
		to_read = read(fd, alocate + current_position, BUFFER_SIZE);
		if (to_read == -1)
		{
			free (alocate);
			return (NULL);
		}
		newline_ptr = strchr(alocate + current_position, '\n');
		if (newline_ptr != NULL)
		{
			*newline_ptr = '\0';
			current_position += newline_ptr - (alocate + current_position) + 1;
			break;
		}
		else
		{
			current_position += to_read;
		}
	}

	p = alocate;
	return (p);
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
