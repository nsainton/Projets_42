/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:08:55 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/02 00:44:51 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "limits.h"

void	ft_putnbr(unsigned long long int nb)
{
	static char base[10] = "0123456789";
	if (nb < 10)
		write(1, base + nb, 1);
	else
	{
		if (nb / 10)
			ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
	
int	main(void)
{
	int	i;

	i = printf("%p\n", (void*)-1);
	printf("%d\n", i);
	ft_putnbr((long long int)((void *)-1));
	i = printf("%p\n", (void *)ULONG_MAX);
	printf("%d\n", i);
	return (0);
}
