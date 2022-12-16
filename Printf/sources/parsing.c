/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:33:37 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/16 18:10:30 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	parse_conv(int *width, int *prec, const char **conv, char flags[128])
{
	ft_bzero(flags, 128);
	while (ft_strchr(FLAGS, **conv) != NULL)
	{
		flags[(int)**conv] = 1;
		*conv += 1;
	}
	*width = ft_atoi(*conv);
	while (ft_strchr(DEC, **conv) != NULL)
		*conv += 1;
	if (**conv == '.')
	{
		flags['.'] = 1;
		*conv += 1;
	}
	if (**conv == '-')
		conv += 1;
	*prec = ft_atoi(*conv);
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
