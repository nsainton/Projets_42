/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:07:48 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/26 21:04:23 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vdprintf(STDOUT_FILENO, format, ap);
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
	init_pbuf_fd(&buf, fd);
	init_func(func);
	while (*s)
	{
		loop(&buf, &s);
		if (! *s)
			break ;
		parse_conv(&buf.width, &buf.prec, &s, flags);
		func[(int)*s](&buf, &cpy, flags);
		s ++;
		if (buf.printed == -1)
			break ;
	}
	flush(&buf);
	return (buf.printed);
}
