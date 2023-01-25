/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:27:10 by vcodrean          #+#    #+#             */
/*   Updated: 2023/01/24 11:58:06 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	//int		fd1;
    int     fd2;
    int     fd3;
	//char	*line;
    char	*line1;
    char	*line2;
    
    //fd1 = open("gnl_lotr.txt", O_RDWR);
    fd2 = open("text.txt", O_RDWR);
    fd3 = open("explicacion.txt", O_RDWR);
	//line = get_next_line(fd1);
    line1 = get_next_line(fd2);
    line2 = get_next_line(fd3);
	while (line1 != NULL || line2 != NULL)
	{
		printf("%s", line1);
        free(line1);
        line1 = get_next_line(fd2);

        printf("%s", line2);
        free(line2);
        line2 = get_next_line(fd3);
	}
	free(line1);
    free(line2);
	//close(fd1);
    close(fd2);
    close(fd3);
	return (0);
}
