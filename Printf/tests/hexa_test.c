/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 01:39:28 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/06 05:09:21 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 2)
		return (1);
	i = printf("%#12X\n", ft_atoi(av[1]));
	j = ft_printf("%#12X\n", ft_atoi(av[1]));
	printf("Retour : %d\n", i - 1);
	printf("Retour : %d\n", j - 1);
	i = printf("%#+12.3X\n", ft_atoi(av[1]));
	j = ft_printf("%#12.3X\n", ft_atoi(av[1]));
	printf("Retour : %d\n", i - 1);
	printf("Retour : %d\n", j - 1);
	i = printf("%X\n", ft_atoi(av[1]));
	j = ft_printf("%X\n", ft_atoi(av[1]));
	printf("Retour : %d\n", i - 1);
	printf("Retour : %d\n", j - 1);
	i = printf("%-12.3X\n", ft_atoi(av[1]));
	j = ft_printf("%-12.3X\n", ft_atoi(av[1]));
	printf("Retour : %d\n", i - 1);
	printf("Retour : %d\n", j - 1);
	i = printf("%# 23.7X\n", ft_atoi(av[1]));
	j = ft_printf("%# 23.7X\n", ft_atoi(av[1]));
	printf("Retour : %d\n", i - 1);
	printf("Retour : %d\n", j - 1);
	i = printf("%  +++X\n", ft_atoi(av[1]));
	j = ft_printf("%   +++X\n", ft_atoi(av[1]));
	printf("Retour : %d\n", i - 1);
	printf("Retour : %d\n", j - 1);

	return (0);
}
