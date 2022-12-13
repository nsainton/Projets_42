/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:55:29 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/11 12:51:28 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	size_t			count;
	int				direction;

	if (dest == NULL)
		return (NULL);
	if (src == NULL)
		return (dest);
	i = 0;
	direction = 1;
	count = 0;
	if (dest > src)
	{
		i = n - 1;
		direction = -1;
	}
	while (count < n)
	{
		*((char *)(dest + i)) = *((char *)(src + i));
		i += direction;
		count ++;
	}
	return (dest);
}
