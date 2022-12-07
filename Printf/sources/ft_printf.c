/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:07:48 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/07 03:35:46 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vdprintf(1, format, ap);
	va_end(ap);
	return (ret);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_pbuffer	buf;
	const char	*s;
	char		flags[128];
	t_pfunc		func[128];
	va_list		cpy;

	va_copy(cpy, ap);
	s = format;
	init_pbuf(&buf, fd);
	init_func(func);
	while (*s)
	{
		loop(&buf, &s);
		if (! *s)
			break ;
		parse_conv(&buf, &s, flags);
		func[(int)*s](&buf, &cpy, flags);
		s ++;
		if (buf.printed == -1)
			break ;
	}
	flush(&buf);
	return (buf.printed);
}
