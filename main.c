/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:18:32 by vcodrean          #+#    #+#             */
/*   Updated: 2023/01/25 18:49:01 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("arch.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
		free(line);
		line = get_next_line(fd);
	printf("%s", line);
		free(line);
		line = get_next_line(fd);
	/*while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}*/
	free(line);
	close(fd);
	return (0);
}
