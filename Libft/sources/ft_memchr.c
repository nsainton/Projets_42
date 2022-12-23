/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:39:04 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/23 20:20:54 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ns;
	size_t				i;

	ns = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(ns + i) == (unsigned char)c)
			return ((void *)(s + i));
		i ++;
	}
	return (NULL);
}
