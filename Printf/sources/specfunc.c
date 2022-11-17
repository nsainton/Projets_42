/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:07:47 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/17 18:10:08 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

void	printf_putstr(va_list ap, int *print, int fd, char flag)
{
	char	*s;

	s = va_arg(ap, char *);
	if (flag)
		return ;
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		*print += 6;
	}
	else
	{
		write(fd, s, ft_strlen(s));
		*print += ft_strlen(s);
	}
}

void	printf_putchar(va_list ap, int *print, int fd, char flag)
{
	char	c;

	c = (char)va_arg(ap, int);
	if (flag)
		return ;
	write(fd, &c, 1);
	*print += 1;
}

void	printf_puthex_maj(va_list ap, int *print, int fd, char flag)
{
	int				nbr;
	long long int	number;

	nbr = va_arg(ap, int);
	if (flag && nbr)
	{
		ft_putstr_fd("0X", fd);
		*print += 2;
	}
	if (nbr < 0)
	{
		number = (long long int)(-1 * nbr);
		printf("%#x\n", nbr);
	}
	else
		number = (long long int)nbr;
	printf_putbase(number, "0123456789ABCDEF", print, fd);
}

void	printf_puthex_min(va_list ap, int *print, int fd, char flag)
{
	int				nbr;
	long long int	number;

	nbr = va_arg(ap, int);
	if (flag && nbr)
	{
		ft_putstr_fd("0x", fd);
		*print += 2;
	}
	if (nbr < 0)
		number = (long long int)(-1 * nbr);
	else
		number = (long long int)nbr;
	printf_putbase(number, "0123456789abcdef", print, fd);
}

void	printf_putdec(va_list ap, int *print, int fd, char flag)
{
	int	nbr;

	nbr = va_arg(ap, int);
	if (flag && nbr > -1)
	{
		ft_putchar_fd(flag, fd);
		*print += 1;
	}
	printf_putbase((long long int)nbr, "0123456789", print, fd);
}
