/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:57:34 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/23 20:21:19 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ptrs[2];

	ptrs[0] = (const unsigned char *)s1;
	ptrs[1] = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*(*ptrs + i) != *(*(ptrs + 1) + i))
			break ;
		i ++;
	}
	if (i == n)
		return (0);
	return ((int)(*(*ptrs + i) - *(*(ptrs + 1) + i)));
}
