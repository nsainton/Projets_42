/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:02:41 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/07 07:13:02 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

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
	if (flags[48] && ! flags['.'])
		pads->pad = 48;
	if (flags[32])
		pads->beg = 32;
	if (flags['+'])
		pads->beg = '+';
	if (flags['m'])
		pads->beg = '-';
	if (flags['-'])
		pads->align = 'l';
}

void	init_func(t_pfunc func[128])
{
	func['d'] = &put_dec;
	func['i'] = &put_dec;
	func['c'] = &put_char;
	func['u'] = &put_unsigned;
	func['s'] = &put_string;
	func['p'] = &put_address;
	func['x'] = &put_hex_min;
	func['X'] = &put_hex_maj;
	func['%'] = &put_percent;
}
