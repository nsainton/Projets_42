/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:29:07 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/15 19:42:26 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill_string(char *string, int nbr, int *index)
{
	unsigned int	n;

	if (nbr < 0)
	{
		*(string + *index) = 45;
		*index += 1;
		n = (unsigned int)(-1 * nbr);
		if (n / 10)
			ft_fill_string(string, (int)(n / 10), index);
		ft_fill_string(string, (int)(n % 10), index);
	}
	else if (nbr < 10)
	{
		*(string + *index) = nbr + 48;
		*index += 1;
	}
	else
	{
		ft_fill_string(string, (int)(nbr / 10), index);
		ft_fill_string(string, (int)(nbr % 10), index);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c[12];
	int		index;

	index = 0;
	ft_fill_string(c, n, &index);
	*(c + index) = 0;
	ft_putstr_fd(c, fd);
}
