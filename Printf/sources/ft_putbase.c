/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:27:24 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/14 17:33:00 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static char	ft_capital(char c, int maj)
{
	if (maj)
		return (ft_toupper(c));
	return (ft_tolower(c));
}

void	ft_putbase(int nbr, int maj, const char *base)
{
	unsigned int	nb;
	size_t			len;

	len = ft_strlen(base);
	if (nbr == -2147483648)
	{
		ft_putchar_fd('-', 1);
		nb = (unsigned int)(-1 * nbr);
		if (nb / len)
			ft_putbase((int)(nb / len), maj, base);
		ft_putbase((int)(nb % len), maj, base);
	}
	else if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putbase(-nbr, maj, base);
	}
	else if((size_t)nbr < len)
		ft_putchar_fd(ft_capital(base[nbr], maj), 1);
	else
	{
		ft_putbase(nbr / len, maj, base);
		ft_putbase(nbr % len, maj, base);
	}
}
