/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmemory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:39:33 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/18 19:31:38 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	printf_printmemory(va_list ap, int *printed, int fd, char flag)
{
	void			*p;
	long long int	tmp;

	p = va_arg(ap, void *);
	if (flag)
		return ;
	if (p == NULL)
	{
		ft_putstr_fd("(nil)", fd);
		*printed += ft_strlen("(nil)");
		return ;
	}
	tmp = (long long int)p;
	*printed += 2;
	ft_putstr_fd("0x", fd);
	if (tmp < 0)
		tmp = (LLONG_MAX + tmp + 1);
	printf_putbase(tmp, "0123456789abcdef", printed, fd);
}
