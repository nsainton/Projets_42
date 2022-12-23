/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:07:59 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/11 18:30:29 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*ns;

	if (s == NULL)
		return (NULL);
	ns = s;
	while (*ns)
	{
		if (*ns == c)
			return ((char *)ns);
		ns ++;
	}
	if (*ns == c)
		return ((char *)ns);
	return (NULL);
}
