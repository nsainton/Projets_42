/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:53:02 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/27 02:03:02 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*ns;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	ns = (char *)malloc((i + 1) * sizeof(*ns));
	if (ns == NULL)
		return (NULL);
	ft_memmove(ns, s, i);
	*(ns + i) = 0;
	return (ns);
}
