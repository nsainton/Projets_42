/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:48:55 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/11 19:08:54 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	strncmp(const char *s1, const char *s2, size_t n)
{
	char	stop;
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL)
		return (-1 * (unsigned char)*s2);
	if (s2 == NULL)
		return ((unsigned char)*s1);
	i = 0;
	stop = 1;
	while (i < n && *(s1 + i) && *(s2 + i) && stop)
	{
		if (*(s1 + i) != *(s2 + i))
		{
			stop = 0;
		}
		i ++;
		if (! stop)
			i --;
	}
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}
