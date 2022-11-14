/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmemory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:39:33 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/14 21:02:36 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

void	ft_printmemory(void *p, int maj)
{
	char	c;

	if (maj)
		c = 'X';
	else
		c = 'x';
	ft_putchar_fd('0', 1);
	ft_putchar_fd(c, 1);
	ft_putbase((long long int)p, maj, "0123456789abcdef");
}
