/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:27:24 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/15 16:12:48 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static char	ft_capital(char c, int maj)
{
	if (maj)
		return (ft_toupper(c));
	return (ft_tolower(c));
}

void	ft_putbase(long long int nbr, int maj, const char *base, \
size_t *printed)
{
	unsigned long long int	nb;
	size_t					len;

	len = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		(*printed)++;
		nb = (unsigned long long int)(-1 * nbr);
		if (nb / len)
			ft_putbase((long long int)(nb / len), maj, base, printed);
		ft_putbase((long long int)(nb % len), maj, base, printed);
	}
	else if ((size_t)nbr < len)
	{
		ft_putchar_fd(ft_capital(base[nbr], maj), 1);
		(*printed)++;
	}
	else
	{
		ft_putbase(nbr / len, maj, base, printed);
		ft_putbase(nbr % len, maj, base, printed);
	}
}
