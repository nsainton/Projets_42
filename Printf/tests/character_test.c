/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 03:59:15 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/05 04:29:46 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int	i;
	int	j;

	i = printf("%-12c\n", 'a');
	j = ft_printf("%-12c\n", 'a');
	printf("Retour de printf : %d\n", i);
	printf("Retour de ft_printf : %d\n", j);
	i = printf("%c\n", 'a');
	j = ft_printf("%c\n", 'a');
	printf("Retour de printf : %d\n", i);
	printf("Retour de ft_printf : %d\n", j);
	i = printf("%12c\n", 'a');
	j = ft_printf("%12c\n", 'a');
	printf("Retour de printf : %d\n", i);
	printf("Retour de ft_printf : %d\n", j);
	i = printf("%-12c %c\n", 'a', 'b');
	j = ft_printf("%-12c %c\n", 'a', 'b');
	printf("Retour de printf : %d\n", i);
	printf("Retour de ft_printf : %d\n", j);
	i = printf("%32c\n", 'a');
	j = ft_printf("%32c\n", 'a');
	printf("Retour de printf : %d\n", i);
	printf("Retour de ft_printf : %d\n", j);
	return (0);
}
