/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:49:27 by vcodrean          #+#    #+#             */
/*   Updated: 2023/01/11 12:49:30 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	*depot;

	if (fd < 0)
		return (NULL);
	if ((depot && !ft_strchar(depot, '\n')) || !depot)
		depot = store_data(fd, depot);
	if (!depot)
		return (NULL);
	line = new_line(depot);
	if (!line)
		return (ft_free(&depot));
	depot = clean_depot(depot);
	return (line);
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
