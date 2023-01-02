/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:50:55 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/02 02:11:17 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_bits(t_byte byte, char *on, char *off)
{
	int unsigned i;

	i = 0;
	while (i < 8)
	{
		if (byte & 1 << i)
			write(1, on, ft_strlen(on));
		else
			write(1, off, ft_strlen(off));
		i ++;
	}
}

void	print_bits_integer(int unsigned to_print, char *on, char *off)
{
	int	unsigned	i;
	int	unsigned	tmp;
	t_byte			*byte;

	i = 0;
	tmp = to_print;
	byte = (t_byte *)&tmp;
	while (i < 4)
	{
		print_bits(*(byte + i), on, off);
		i ++;
	}
}
