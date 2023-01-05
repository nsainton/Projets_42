/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:50:55 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/05 17:48:20 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

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

void	print_tmessage(int fd, t_message *message)
{
	ft_dprintf(fd, "This is the structure : t_message\n");
	ft_dprintf(fd, "This is the current number of bytes received : %u\n", message->bytes);
	ft_dprintf(fd, "This is the  current watched bit : %d\n", message->bit);
	ft_dprintf(fd, "This is the current value of len : %u\n", message->length);
	if (message->bytes < 5)
		return ;
	ft_dprintf(fd, "This is the current message : ");
	write(fd, message->message, message->bytes - 4);
	write(fd, "\n", 1);
}
