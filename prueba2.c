/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:14:54 by vcodrean          #+#    #+#             */
/*   Updated: 2023/01/11 13:25:22 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUF_SIZE 8

char	*get_next_line(int fd)
{
	static char		storage[1024];
	static int		len;
	int				ret;
	char			*new_line;
	char			*line;

	len = 0;
	ret = read(fd, storage + len, BUF_SIZE);
	//*new_line = NULL;
	if (fd < 0)
		return (NULL);
	while (!new_line && ret > 0)
	{
		len += ret;
		storage[len] = '\0';
		new_line = strchr(storage, '\n');
	}
	if (ret < 0 || !len)
		return (NULL);
	*new_line = '\0';
	line = strdup(storage);
	len -= new_line - storage + 1;
	memmove(storage, new_line + 1, len + 1);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf ("%s", line);
	line = get_next_line(fd);
	printf ("%s", line);
	free(line);
	close(fd);
	return (0);
}
