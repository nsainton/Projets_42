/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:31:17 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/05 01:56:35 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	put_unsigned(t_ull nb, char **tab, char *base)
{
	t_ull	i;

	i = (t_ull)ft_strlen(base);
	if (nb < i)
	{
		**tab = *(base + nb);
		*tab += 1;
	}
	else
	{
		put_unsigned(nb / i, tab, base);
		put_unsigned(nb % i, tab, base);
	}
}

void	put_dec(t_pbuffer *buf, va_list *ap, char flags[128])
{
	int		len;
	int		arg;
	char	nb[66];
	char	*tmp;

	tmp = nb;
	arg = va_arg(*ap, int);
	put_unsigned(abs_ll((t_ll)arg), &tmp, DEC);
	len = (int)(tmp - nb);
	*tmp = 0;
	if (!(arg || buf->prec) && flags[(int) '.'])
	{
		*nb = 0;
		len = 0;
	}
	if (arg < 0)
		flags[(int) 'm'] = 1;
	build_res(buf, nb, flags, len);
}
