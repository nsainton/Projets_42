/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:57:34 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/09 12:12:24 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ptrs[2];

	ptrs[0] = (const unsigned char *)s1;
	ptrs[1] = (const unsigned char *)s2;
	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL)
		return (- (int)(**(ptrs + 1)));
	if (s2 == NULL)
		return ((int)(**ptrs));
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
