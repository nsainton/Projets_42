/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:53:02 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/13 11:53:05 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	j;
	char	*ns;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	ns = (char *)malloc((i + 1) * sizeof(*ns));
	if (ns == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		*(ns + j) = *(s + j);
		j ++;
	}
	*(ns + j) = 0;
	return (ns);
}
