/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:53:45 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/05 14:01:13 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NULL ((void *)0)

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (div == NULL || mod == NULL || ! b)
		return ;
	*div = a / b;
	*mod = a % b;
}

#include <stdio.h>
int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 42;
	b = 21;
	ft_div_mod(a, b, &div, &mod);
	printf("Voici le quotient de la division de a par b : div = %d\n", div);
	printf("Voici le reste de la division de a par b : mod = %d\n", mod);
	return (0);
}
