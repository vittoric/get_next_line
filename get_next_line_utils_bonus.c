/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:45:15 by marvin            #+#    #+#             */
/*   Updated: 2023/01/18 15:45:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *depot, char *buf)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!depot)
	{
		depot = malloc(sizeof(char) + 1);
		if (!depot)
			return (NULL);
		depot[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(depot) + ft_strlen(buf) + 1);
	if (!str)
		return (ft_free(&depot));
	i = -1;
	while (depot[++i])
		str[i] = depot[i];
	c = -1;
	while (buf[++c])
		str[i + c] = buf[c];
	str[i + c] = '\0';
	free(depot);
	return (str);
}

char	*ft_substr(char *depot, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!depot)
		return (0);
	if (start > ft_strlen(depot))
	{
		res = malloc(sizeof(char) * (1));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (ft_strlen(depot) - start < len)
		len = ft_strlen(depot) - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (start < ft_strlen(depot) && i < len && depot[start])
		res[i++] = depot[start++];
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchar(char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&((char *)str)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)str)[i]);
	return (0);
}
