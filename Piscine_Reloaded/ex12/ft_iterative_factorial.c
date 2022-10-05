/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:04:26 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/05 14:17:00 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	fact;

	if (nb < 0)
		return (0);
	if (! nb)
		return (1);
	fact = 1;
	while (nb > 1)
	{
		fact *= nb;
		if (fact < 0)
			return (0);
		nb --;
	}
	return (fact);
}

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	i;
	int	num;

	i = 1;
	while (i < ac)
	{
		num = atoi(av[i]);
		printf("Voici la factorielle de %d : %d\n", num, \
		ft_iterative_factorial(num));
		i ++;
	}
	return (0);
}
