/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmemory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:39:33 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/14 19:03:56 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

void	ft_printmemory(unsigned char *ptr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_putbase(*(p + i), 1, "0123456789abcdef");
		//ft_putnbr_fd(*(p + i), 1);
		ft_putchar_fd(' ', 1);
		i ++;
	}
	i = 0;
	while (i < size)
	{
		ft_putchar_fd(*(p + i), 1);
		i ++;
	}
}

int	main(void)
{
	char	a[20] = "Bonjour";

	ft_printmemory((unsigned char*)a, ft_strlen(a));
	ft_putchar_fd('\n', 1);
	printf("%p\n", a);
	return (0);
}
