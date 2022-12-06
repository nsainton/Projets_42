/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 05:03:22 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/06 00:57:51 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int		i;
	int		j;

	i = printf("%p\n", (void *)-1);
	j = ft_printf("%p\n", (void *)-1);
	printf("Retour de printf : %d\n", i);
	printf("Retour de ft_printf : %d\n", j);
	i = printf("%32p\n", (void *)-1);
	j = ft_printf("%32p\n", (void *)-1);
	printf("Retour de printf : %d\n", i);
	printf("Retour de ft_printf : %d\n", j);
	i = printf("%-32p\n", (void *)-1);
	j = ft_printf("%-32p\n", (void *)-1);
	printf("Retour de printf : %d\n", i);
	printf("Retour de ft_printf : %d\n", j);
	i = printf("%p\n", (void *)0);
	j = ft_printf("%p\n", (void *)0);
	printf("Retour de printf : %d\n", i);
	printf("Retour de ft_printf : %d\n", j);
	i = printf("%p\n", (void *)150);
	j = ft_printf("%p\n", (void *)150);
	printf("Retour de printf : %d\n", i);
	printf("Retour de ft_printf : %d\n", j);
	i = printf("%3p\n", (void *)-145);
	j = ft_printf("%3p\n", (void *)-145);
	printf("Retour de printf : %d\n", i);
	printf("Retour de ft_printf : %d\n", j);
	return (0);
}
