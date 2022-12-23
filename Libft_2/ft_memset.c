/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:11:59 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/09 08:42:58 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	letter;

	if (b == NULL)
		return (NULL);
	str = (unsigned char *)b;
	letter = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		*(str + i) = letter;
		i ++;
	}
	return (b);
}
