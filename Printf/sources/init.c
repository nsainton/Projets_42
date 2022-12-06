/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:02:41 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/06 05:14:48 by nsainton         ###   ########.fr       */
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
	flags[(int) '.'] = 0;
}

void	init_pbuf(t_pbuffer *buf, int fd)
{
	buf->fd = fd;
	buf->len = 0;
	buf->printed = 0;
	buf->width = 0;
	buf->prec = 0;
}

void	set_pad(char flags[128], t_print *pads)
{
	pads->beg = 0;
	pads->pad = ' ';
	pads->modifier[0] = 0;
	pads->align = 'r';
	if (flags[48] && ! flags[(int) '.'])
		pads->pad = 48;
	if (flags[32])
		pads->beg = 32;
	if (flags[(int) '+'])
		pads->beg = '+';
	if (flags[(int) 'm'])
		pads->beg = '-';
	if (flags[(int) '-'])
		pads->align = 'l';
}

void	init_func(t_pfunc func[128])
{
	func[(int) 'd'] = &put_dec;
	func[(int) 'i'] = &put_dec;
	func[(int) 'c'] = &put_char;
	func[(int) 'u'] = &put_unsigned;
	func[(int) 's'] = &put_string;
	func[(int) 'p'] = &put_address;
	func[(int) 'x'] = &put_hex_min;
	func[(int) 'X'] = &put_hex_maj;
	func[(int) '%'] = &put_percent;
}
