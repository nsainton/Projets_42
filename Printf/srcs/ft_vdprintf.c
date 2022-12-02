/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:26:40 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/17 18:02:17 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

static void	loop(const char **s, int fd, int *printed)
{
	while (**s && **s != '%')
	{
		ft_putchar_fd(**s, fd);
		*s += 1;
		*printed += 1;
	}
}

static int	isvalid(char c)
{
	char	*s;
	char	*t;

	s = ft_strchr("# +", c);
	t = ft_strchr("cspdiuxX%", c);
	if (!(s || t))
		return (0);
	if (s)
		return (2);
	return (1);
}

static void	init(void (*f[128])(va_list, int *, int, char), int *initialized)
{
	f['d'] = &printf_putdec;
	f['u'] = &printf_unsigned;
	f['i'] = f['d'];
	f['x'] = &printf_puthex_min;
	f['X'] = &printf_puthex_maj;
	f['p'] = &printf_printmemory;
	f['s'] = &printf_putstr;
	f['%'] = &printf_percent;
	f['c'] = &printf_putchar;
	*initialized = 1;
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	static int	initialized = 0;
	int			printed;
	static void	(*f[128])(va_list, int *, int, char);

	if (! initialized)
		init(f, &initialized);
	if (format == NULL)
		return (0);
	printed = 0;
	while (*format)
	{
		loop(&format, fd, &printed);
		if (*format == 0)
			return (printed);
		format ++;
		if (isvalid(*format) == 1)
			f[(int)*format](ap, &printed, fd, 0);
		else if (isvalid(*format) == 2)
			f[(int)*(format + 1)](ap, &printed, fd, *format);
		else
			return (printed);
		format += isvalid(*format);
	}
	return (printed);
}
