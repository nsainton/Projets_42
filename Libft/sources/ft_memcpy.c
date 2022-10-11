/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:44:46 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/09 13:57:27 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	int		i;
	char	*ns;

	if (dest == NULL)
		return (NULL);
	if (src == NULL)
		return (dest);
	i = 0;
	ns = (char *)dest;
	while (i < n)
	{
		*(ns + i) = *(src + i);
		i ++;
	}
	return (dest);
}
