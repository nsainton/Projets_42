/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:02:41 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/05 01:38:23 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	reset_flags(char flags[128])
{
	int	i;

	i = 0;
	while (FLAGS[i])
	{
		flags[(int)FLAGS[i]] = 0;
		i ++;
	}
	flags[(int) 'm'] = 0;
}

void	init_pbuf(t_pbuffer *buf, int fd)
{
	buf->fd = fd;
	buf->len = 0;
	buf->printed = 0;
	buf->width = 0;
	buf->prec = 0;
}

void	set_pad(t_pbuffer *buf, char flags[128], t_print *pads)
{
	pads->beg = 0;
	pads->pad = ' ';
	pads->modifier[0] = 0;
	pads->align = 0;
	if (flags[48] && ! buf->prec)
		pads->pad = 48;
	if (flags[32])
		pads->beg = 32;
	if (flags[(int) '+'])
		pads->beg = '+';
	if (flags[(int) 'm'])
		pads->beg = '-';
	if (flags[(int) '-'])
		pads->align = 1;
}

void	init_func(t_pfunc func[128])
{
	func[(int) 'd'] = &put_dec;
}
