/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:06:23 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/16 15:06:08 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_fill_string(char *new_string, const char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		*(new_string + i) = *(s1 + i);
		i ++;
	}
	j = 0;
	while (j < size)
	{
		*(new_string + i + j) = *(s2 + j);
		j ++;
	}
}

char	*ft_strrealloc(char *dest, const char *src, size_t size)
{
	static size_t	f_size = 0;
	char			*ns;

	if (! src)
		return (dest);
	f_size += size;
	ns = (char *)malloc(f_size * sizeof(char));
	if (! ns)
		return (NULL);
	ft_fill_string(ns, dest, src);
	free(dest);
	return (ns);
}

size_t	ft_newline(char *buf, size_t size)
{
	size_t	i;

	if (buf == NULL)
		return (0);
	while (i < size)
	{
		if (*(buf + i) == 10)
			return (i + 1);
		i ++;
	}
	return (0);
}

char	*ft_getline(char *buf)
{
	size_t i;
	size_t nl;
	if (buf == NULL)
		return (NULL);
	

/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", BUFF_SIZE);
	return (0);
}
*/
