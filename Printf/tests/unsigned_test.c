/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 04:33:37 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/05 05:01:03 by nsainton         ###   ########.fr       */
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
	i = printf("%3u\n", ft_atoi(av[1]));
	j = ft_printf("%3u\n", ft_atoi(av[1]));
	printf("Retour de la fonction printf : %d\n", i);
	printf("Retour de la fonction ft_printf : %d\n", j);
	i = printf("%3.12u\n", ft_atoi(av[1]));
	j = ft_printf("%3.12u\n", ft_atoi(av[1]));
	printf("Retour de la fonction printf : %d\n", i);
	printf("Retour de la fonction ft_printf : %d\n", j);
	i = printf("%-30u\n", ft_atoi(av[1]));
	j = ft_printf("%-30u\n", ft_atoi(av[1]));
	printf("Retour de la fonction printf : %d\n", i);
	printf("Retour de la fonction ft_printf : %d\n", j);
	i = printf("%03u\n", ft_atoi(av[1]));
	j = ft_printf("%03u\n", ft_atoi(av[1]));
	printf("Retour de la fonction printf : %d\n", i);
	printf("Retour de la fonction ft_printf : %d\n", j);
	i = printf("%3.u\n", ft_atoi(av[1]));
	j = ft_printf("%3.u\n", ft_atoi(av[1]));
	printf("Retour de la fonction printf : %d\n", i);
	printf("Retour de la fonction ft_printf : %d\n", j);
	i = printf("%12.3u\n", ft_atoi(av[1]));
	j = ft_printf("%12.3u\n", ft_atoi(av[1]));
	printf("Retour de la fonction printf : %d\n", i);
	printf("Retour de la fonction ft_printf : %d\n", j);
	return (0);
}
