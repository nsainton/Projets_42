/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:12:26 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/14 16:20:54 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

void	print(int tab[], int size)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	ft_putstr_fd("Voici les elements du tableau : ", 1);
	while (i < size - 1)
	{
		ft_putnbr_fd(tab[i], 1);
		ft_putstr_fd(" + ", 1);
		sum += tab[i];
		i ++;
	}
	sum += tab[i];
	ft_putnbr_fd(tab[i], 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Voici leur somme : ", 1);
	ft_putnbr_fd(sum, 1);
	ft_putchar_fd('\n', 1);
}

void	test(int nbr_args, ...)
{
	int		i;
	int		tab[10];
	va_list	arg;

	i = 0;
	va_start(arg, nbr_args);
	while (i < nbr_args)
	{
		tab[i] = va_arg(arg, int);
		i ++;
	}
	va_end(arg);
	print(tab, nbr_args);
}

int	main(void)
{
	test(2, 10, 10);
	test(2, 10, 20);
	test(3, 10, 10, 10);
	test(3, 19);
	test(1, 20);
	test(1);
	return (0);
}
