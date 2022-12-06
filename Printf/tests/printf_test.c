/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 06:00:16 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/06 06:21:27 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	test_dec(int a);
int	main(void)
{
	int	i;

	printf("-----------------Test de %%d---------------\n");
	printf("Le cas special 0\n");
	test_dec(0);
	printf("Le cas special de INT_MIN\n");
	test_dec(-2147483648);
	printf("Le cas special de INT_MAX\n");
	test_dec(2147483647);
	printf("Avec -213\n");
	test_dec(-213);
	printf("Avec -3\n");
	test_dec(-3);
	printf("Avec 2\n");
	test_dec(2);
	printf("Avec 239\n");
	test_dec(239);
	return (0);
}
