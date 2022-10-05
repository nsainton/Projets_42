/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:28:07 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/05 13:30:20 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

#include <stdio.h>
int	main(void)
{
	int	nbr;
	int	*p;

	p = &nbr;
	ft_ft(p);
	printf("Voici la valeur contenur dans le nombre : %d\n", nbr);
	return (0);
}
