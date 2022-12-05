/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 02:27:16 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/05 03:16:12 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include "../includes/debug.h"

void	build_res(t_pbuffer *buf, char *nb, char flags[128], int len)
{
	t_print	pads;
	int		tmp;

	set_pad(buf, flags, &pads);
	tmp = 0;
	if (pads.beg)
		tmp = 1;
	buf->prec = max_int(buf->prec, len);
	buf->width = max_int(buf->prec + tmp, buf->width);
	print_res(buf, nb, len, &pads);
}

void	print_res(t_pbuffer *buf, char *nb, int len, t_print *pads)
{
	int	width;
	int	prec;

	width = buf->width;
	prec = buf->prec;
	/*
	print_pad(pads);
	printf("------\n");
	print_buffer(buf);
	printf("----\n");
	*/
	if (pads->beg)
		width -= 1;
	if (pads->align == 'r' && pads->pad == ' ')
		add_nchar(buf, pads->pad, width - prec);
	if (pads->beg)
		add_char(buf, pads->beg);
	if (pads->align == 'r' && pads->pad == '0')
		add_nchar(buf, pads->pad, width - prec);
	add_nchar(buf, '0', prec - len);
	add_str(buf, nb);
	if (pads->align == 'l')
		add_nchar(buf, ' ', width - prec);
}
