/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmemory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:39:33 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/17 02:37:46 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	printf_printmemory(va_list ap, int *printed, int fd, char flag)
{
	void	*p;

	p = va_arg(ap, void *);
	if (flag)
		return ;
	if (p == NULL)
	{
		ft_putstr_fd("(nil)", fd);
		*printed += ft_strlen("(nil)");
		return ;
	}
	*printed += 2;
	ft_putstr_fd("0x", fd);
	ft_putbase((long long int)p, "0123456789abcdef", printed, fd);
}
