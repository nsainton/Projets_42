/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specfunc2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:54:22 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/17 02:11:26 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	printf_percent(va_list ap, int *print, int fd, char flag)
{
	if (flag)
		return ;
	write(fd, "%", 1);
	*print += 1;
}

void	printf_unsigned(va_list ap, int *print, int fd, char flag)
{
	unsigned int	nbr;

	nbr = va_arg(ap, unsigned int);
	if (flag && nbr > -1)
	{
		ft_putchar_fd(flag, fd);
		*print += 1;
	}
	printf_putbase((long long int)nbr, "0123456789", print, fd);
}
