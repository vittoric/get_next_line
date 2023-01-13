/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:15:59 by vcodrean          #+#    #+#             */
/*   Updated: 2023/01/13 15:49:27 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include  <fcntl.h>
# include  <stdio.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# if BUFFER_SIZE > 9223372036854775806L
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>
# include<limits.h>

char	*get_next_line(int fd);
char	*readbuff(int fd, char *depot);
char	*new_line(char *depot);
char	*ft_strchar(char *str, int c);
char	*ft_free(char **str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(char *str);
char	*clean_depot(char *depot);

#endif