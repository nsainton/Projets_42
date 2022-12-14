/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 06:13:18 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/14 10:09:54 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

void	test_dec(int a)
{
	int	i;

	i = printf("%d\n", a);
	printf("Retour de la fonction : %d\n", i);
	i = printf("%.d\n", a);
	printf("Retour de la fonction : %d\n", i);
	i = printf("%.3d\n", a);
	printf("Retour de la fonction : %d\n", i);
	i = printf("% 0.2d\n", a);
	printf("Retour de la fonction : %d\n", i);
	i = printf("%+ 0d\n", a);
	printf("Retour de la fonction : %d\n", i);
	i = printf("% 12.34d\n", a);
	printf("Retour de la fonction : %d\n", i);
	i = printf("%+-12.32d\n", a);
	printf("Retour de la fonction : %d\n", i);
	i = printf("%+12.2d\n", a);
	printf("Retour de la fonction : %d\n", i);
	i = printf("%+ 2.12d\n", a);
	printf("Retour de la fonction : %d\n", i);
	i = printf("% 0-d\n", a);
	printf("Retour de la fonction : %d\n", i);
}

void	ft_test_dec(int a)
{
	int	i;

	i = ft_printf("%d\n", a);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("%.d\n", a);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("%.3d\n", a);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("% 0.2d\n", a);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("%+ 0d\n", a);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("% 12.34d\n", a);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("%+-12.32d\n", a);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("%+12.2d\n", a);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("%+ 2.12d\n", a);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("% 0-d\n", a);
	ft_printf("Retour de la fonction : %d\n", i);
}
