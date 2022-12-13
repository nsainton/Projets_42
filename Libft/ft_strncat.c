/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:30:49 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/01 22:37:37 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	dst_len;

	dst_len = ft_strlen(dest);
	i = 0;
	while (i < n && *(src + i))
	{
		*(dest + dst_len + i) = *(src + i);
		i ++;
	}
	*(dest + dst_len + i) = 0;
	return (dest);
}
