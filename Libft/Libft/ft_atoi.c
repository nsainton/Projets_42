/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:16:04 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/12 17:33:45 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return ((c == 32 || (c > 8 && c < 14)));
}

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	i;
	int	minus;

	if (nptr == NULL)
		return (0);
	nbr = 0;
	i = 0;
	minus = 1;
	while (ft_isspace((int)*(nptr + i)))
		i ++;
	if (*(nptr + i) == 43 || *(nptr + i) == 45)
	{
		if (*(nptr + i) == 45)
			minus = -1;
		i ++;
	}
	while (ft_isdigit((int)*(nptr + i)))
	{
		nbr = nbr * 10 + ((int)*(nptr + i) - 48);
		i ++;
	}
	return (minus * nbr);
}
