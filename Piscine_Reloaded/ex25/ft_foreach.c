/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:19:37 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/05 23:55:08 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	if (tab == NULL || length < 1 || f == NULL)
		return ;
	i = 0;
	while (i < length)
	{
		f(*(tab + i));
		i ++;
	}
}

//TEST
#include <unistd.h>
#include <stdlib.h>

void	ft_putdigit(int dig)
{
	char	c;

	c = dig + 48;
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	n;

	if (nb < 0)
	{
		write(1, "-", 1);
		n = (unsigned int)(-1 * nb);
		if (n / 10)
			ft_putnbr((int)(n / 10));
		ft_putdigit((int)(n % 10));
	}
	else
	{
		if (nb / 10)
			ft_putnbr(nb / 10);
		ft_putdigit(nb % 10);
	}
}

int	main(int ac, char **av)
{
	int	tab[100];
	int	i;

	i = 0;
	while (i < ac)
	{
		*(tab + i) = atoi(av[i]);
		i ++;
	}
	ft_foreach(tab, ac, &ft_putnbr);
	return (0);
}
