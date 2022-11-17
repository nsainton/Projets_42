/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putbase.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:27:24 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/17 01:24:14 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	printf_putbase(long long int nbr, const char *base, \
int *printed, int fd)
{
	unsigned long long int	nb;
	size_t					len;

	len = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		(*printed)++;
		nb = (unsigned long long int)(-1 * nbr);
		if (nb / len)
			ft_putbase((long long int)(nb / len), base, printed, fd);
		ft_putbase((long long int)(nb % len), base, printed, fd);
	}
	else if (nbr < (long long int)len)
	{
		ft_putchar_fd(base[nbr], fd);
		(*printed)++;
	}
	else
	{
		ft_putbase(nbr / len, base, printed, fd);
		ft_putbase(nbr % len, base, printed, fd);
	}
}
