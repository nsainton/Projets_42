/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:26:40 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/17 02:43:39 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void	loop(char **s, int fd, int *printed)
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

static void	init(void (*f)(va_list, int *, int, char), int *initialized)
{
	f['d'] = &printf_putdec;
	f['u'] = &printf_unsigned;
	f['i'] = f['d'];
	f['x'] = &printf_puthex_min;
	f['X'] = &printf_puthex_maj;
	f['p'] = &printf_printmemory;
	f['s'] = &printf_putstr;
	f['%'] = &printf_percent;
	*initialized = 1;
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	size_t		i;
	static int	initialized = 0;
	int			printed;
	static void	(*f)(va_list, int *, int, char)[128];

	if (! initialized)
		init(f, &initialized);
	if (format == NULL)
		return (0);
	printed = 0;
	while (*format)
	{
		loop(&format, fd, &printed);
		format ++;
		if (isvalid(*format) == 1)
			f[*(format + 1)](ap, &printed, fd, *format);
		if (isvalid(*format) == 2)
			f[*format](ap, &printed, fd, 0);
		format += isvalid(*format);
	}
	return (printed);
}
