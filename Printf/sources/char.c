/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 03:57:04 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/05 04:06:41 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	put_char(t_pbuffer *buf, va_list *ap, char flags[128])
{
	char	align;
	char	arg;

	arg = (char)va_arg(*ap, int);
	align = 'r';
	if (flags[(int) '-'])
		align = 'l';
	if (align == 'r')
		add_nchar(buf, ' ', buf->width - 1);
	add_char(buf, arg);
	if (align == 'l')
		add_nchar(buf, ' ', buf->width - 1);
}
