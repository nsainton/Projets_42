/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:08:26 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/05 23:12:15 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int		i;
	char	stop;

	if (s1 == NULL || s2 == NULL)
		return (0);
	stop = 1;
	i = 0;
	while (*(s1 + i) && *(s2 + i) && stop)
	{
		if (*(s1 + i) != *(s2 + i))
		{
			stop = 0;
			i --;
		}
		i ++;
	}
	return ((unsigned int)*(s1 + i) - \
	(unsigned int)*(s2 + i));
}
