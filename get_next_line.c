/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:18:01 by vcodrean          #+#    #+#             */
/*   Updated: 2023/01/05 18:17:58 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		to_read;
	char	*p;
	char	*alocate;

	alocate = malloc(sizeof(char) * (BUFFER_SIZE +1));
	if (alocate == NULL)
	{
		return (NULL);
	}
	to_read = read(fd, alocate, BUFFER_SIZE);
	if (to_read == -1)
	{
		free (alocate);
		return (NULL);
	}
	alocate[to_read] = '\0';
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
