/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 02:03:24 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/05 02:18:29 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 2)
		return (1);
		/*
	i = ft_printf("%d\n", ft_atoi(av[1]));
	j = printf("%d\n", ft_atoi(av[1]));
	printf("Retour de printf : %d\n", j);
	printf("Retour de ft_printf : %d\n", i);
	i = ft_printf("%.d\n", ft_atoi(av[1]));
	j = printf("%.d\n", ft_atoi(av[1]));
	printf("Retour de printf : %d\n", j);
	printf("Retour de ft_printf : %d\n", i);
	*/
	i = ft_printf("%+12.2d\n", ft_atoi(av[1]));
	j = printf("%+12.2d\n", ft_atoi(av[1]));
	printf("Retour de printf : %d\n", j);
	printf("Retour de ft_printf : %d\n", i);
	/*
	i = ft_printf("%+031d\n", ft_atoi(av[1]));
	j = printf("%+031d\n", ft_atoi(av[1]));
	printf("Retour de printf : %d\n", j);
	printf("Retour de ft_printf : %d\n", i);
	i = ft_printf("% 1.7d\n", ft_atoi(av[1]));
	j = printf("% 1.7d\n", ft_atoi(av[1]));
	printf("Retour de printf : %d\n", j);
	printf("Retour de ft_printf : %d\n", i);
	*/
	return (0);
}
