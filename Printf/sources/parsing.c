/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:33:37 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/05 01:59:57 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	parse_conv(t_pbuffer *buf, const char **conv, char flags[128])
{
	reset_flags(flags);
	while (ft_strchr(FLAGS, **conv) != NULL)
	{
		flags[(int)**conv] = 1;
		*conv += 1;
	}
	buf->width = ft_atoi(*conv);
	while (ft_strchr(DEC, **conv) != NULL)
		*conv += 1;
	if (**conv == '.')
	{
		flags[(int) '.'] = 1;
		*conv += 1;
	}
	buf->prec = ft_atoi(*conv);
	buf->prec = max_int(buf->prec, -buf->prec);
	while (ft_strchr(DEC, **conv))
		*conv += 1;
}

void	loop(t_pbuffer *buf, const char **conv)
{
	while (**conv && **conv != '%')
	{
		add_char(buf, **conv);
		*conv += 1;
	}
	if (**conv == '%')
		*conv += 1;
}
