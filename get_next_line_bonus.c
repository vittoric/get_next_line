/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:45:05 by marvin            #+#    #+#             */
/*   Updated: 2023/01/18 15:45:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char			*line;
	static char		*depot[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((depot[fd] && !ft_strchar(depot[fd], '\n')) || !depot[fd])
		depot[fd] = readbuff(fd, depot[fd]);
	if (!depot[fd])
		return (NULL);
	line = new_line(depot[fd]);
	if (!line)
		return (ft_free(&depot[fd]));
	depot[fd] = clean_depot(depot[fd]);
	return (line);
}

char	*readbuff(int fd, char *depot)
{
	int		to_read;
	char	*buffer;

	if (fd < 0)
		return (NULL);
	to_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&depot));
	buffer[0] = '\0';
	while (to_read > 0 && !ft_strchar(buffer, '\n'))
	{
		to_read = read (fd, buffer, BUFFER_SIZE);
		if (to_read > 0)
		{
			buffer[to_read] = '\0';
			depot = ft_strjoin(depot, buffer);
		}
	}
	free(buffer);
	if (to_read == -1)
		return (ft_free(&depot));
	return (depot);
}

char	*new_line(char *depot)
{
	char	*line;
	char	*p;
	int		len;

	p = ft_strchar(depot, '\n');
	len = (p - depot) + 1;
	line = ft_substr(depot, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*clean_depot(char *depot)
{
	char	*new_depot;
	char	*p;
	int		len;

	p = ft_strchar(depot, '\n');
	if (!p)
	{
		new_depot = NULL;
		return (ft_free(&depot));
	}
	else
		len = (p - depot) + 1;
	if (!depot[len])
		return (ft_free(&depot));
	new_depot = ft_substr(depot, len, ft_strlen(depot) - len);
	ft_free(&depot);
	if (!new_depot)
		return (NULL);
	return (new_depot);
}

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}
/*
int		main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf ("%s", line);
	free(line);
	close(fd);
	return (0);
}*/
