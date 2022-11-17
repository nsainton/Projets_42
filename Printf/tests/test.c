/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:45:18 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/17 02:09:28 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <unistd.h>

/*
void	ft_putnbr_dec(int nbr);

void	test(int nbr)
{
	ft_putnbr_dec(nbr);
	write(1, "\n", 1);
}

void	ft_putnbr_dec(int nbr)
{
	unsigned int	nb;
	static int		Switch = 1;
	static char		base[11] = "012345689";

	if (Switch && nbr > -1)
	{
		Switch = 0;
		write(1, " ", 1);
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nb = (unsigned int)(-1 * nbr);
		if (nb / 10)
			ft_putnbr_dec((int)(nb / 10));
		ft_putnbr_dec((int)(nb % 10));
	}
	else
	{
		if (nbr / 10)
			ft_putnbr_dec(nbr / 10);
		write(1, base + nbr % 10, 1);
	}
}
*/

int	main(void)
{
	printf("% p\n", NULL);
	return (0);
}
