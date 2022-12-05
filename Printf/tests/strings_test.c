/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 07:01:49 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/05 07:52:56 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	*s = NULL;
	char	tab[100];

	if (ac != 2)
		return (1);
	tab[0] = 'a';
	tab[1] = 'b';
	tab[2] = 'c';
	i = ft_printf("%s\n", av[1]);
	j = printf("%s\n", av[1]);
	printf("Retour de ft_printf : %d\n", i);
	printf("Retour de printf : %d\n", j);
	i = ft_printf("%.3s\n", av[1]);
	j = printf("%.3s\n", av[1]);
	printf("Retour de ft_printf : %d\n", i);
	printf("Retour de printf : %d\n", j);
	i = ft_printf("%12s\n", av[1]);
	j = printf("%12s\n", av[1]);
	printf("Retour de ft_printf : %d\n", i);
	printf("Retour de printf : %d\n", j);
	i = ft_printf("%12.3s\n", av[1]);
	j = printf("%12.3s\n", av[1]);
	printf("Retour de ft_printf : %d\n", i);
	printf("Retour de printf : %d\n", j);
	i = ft_printf("%3.12s\n", av[1]);
	j = printf("%3.12s\n", av[1]);
	printf("Retour de ft_printf : %d\n", i);
	printf("Retour de printf : %d\n", j);
	i = ft_printf(" %s\n", s);
	j = printf(" %s\n", s);
	printf("Retour de ft_printf : %d\n", i);
	printf("Retour de printf : %d\n", j);
	i = ft_printf(" %.3s\n", s);
	j = printf(" %.3s\n", s);
	printf("Retour de ft_printf : %d\n", i);
	printf("Retour de printf : %d\n", j);
	i = ft_printf(" %.3s\n", s);
	j = printf(" %.3s\n", s);
	printf("Retour de ft_printf : %d\n", i);
	printf("Retour de printf : %d\n", j);
	i = ft_printf(" %.3s\n", tab);
	j = printf(" %.3s\n", tab);
	printf("Retour de ft_printf : %d\n", i);
	printf("Retour de printf : %d\n", j);

	return (0);
}
