/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:32:29 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/05 18:36:23 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NULL ((void*)0)

void	ft_swap(int *a, int *b)
{
	int	tmp;

	if (a == NULL || b == NULL)
		return ;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	a = 21;
	b = 42;
	printf("Voici les valeurs de a et b avant échange : ");
	printf("a = %d et b = %d\n", a, b);
	ft_swap(&a, &b);
	printf("Voici les valeurs de a et b après échange : ");
	printf("a = %d et b = %d\n", a, b);
	return (0);
}
