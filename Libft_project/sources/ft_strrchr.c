/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:10:48 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/11 18:31:06 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ns;
	char	*res;

	if (s == NULL)
		return (NULL);
	ns = (char *)s;
	res = NULL;
	while (*ns)
	{
		if (*ns == c)
			res = ns;
		ns ++;
	}
	if (*ns == c)
		res = ns;
	return (res);
}
