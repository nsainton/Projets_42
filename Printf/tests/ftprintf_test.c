/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 06:00:16 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/06 06:38:55 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
void	ft_test_dec(int a);
int	main(void)
{
	ft_printf("-----------------Test de %%d---------------\n");
	ft_printf("Le cas special 0\n");
	ft_test_dec(0);
	ft_printf("Le cas special de INT_MIN\n");
	ft_test_dec(-2147483648);
	ft_printf("Le cas special de INT_MAX\n");
	ft_test_dec(2147483647);
	ft_printf("Avec -213\n");
	ft_test_dec(-213);
	ft_printf("Avec -3\n");
	ft_test_dec(-3);
	ft_printf("Avec 2\n");
	ft_test_dec(2);
	ft_printf("Avec 239\n");
	ft_test_dec(239);
	return (0);
}
