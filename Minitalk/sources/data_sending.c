/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sending.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 01:00:28 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/02 02:18:54 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_bit(char unsigned bit, pid_t receiver)
{
	if (bit && ! kill(receiver, SIGUSR1))
	{
		pause();
		return (0);
	}
	else if (!bit && ! kill(receiver, SIGUSR2))
	{
		pause();
		return (0);
	}
	return (1);
}

int	send_byte(char unsigned byte, pid_t receiver)
{
	int unsigned			i;
	int						t;

	i = 0;
	while (i < 7)
	{
		t = send_bit(byte & 1 << i, receiver);
		//ft_printf("This is the return value for bit[%d] : %d\n", i, t);
		i ++;
		//sleep(1);
	}
	(void)t;
	return (send_bit(byte & 1 << i, receiver));
}

int	send_integer(int unsigned quadruplet, pid_t receiver)
{
	t_byte			*byte;
	int unsigned	tmp;
	int unsigned	index;

	tmp = quadruplet;
	byte = (t_byte *)&tmp;
	index = 0;
	while (index < 3)
		send_byte(*(byte + index ++), receiver);
	return (send_byte(*(byte + index), receiver));
}

void	update_byte(int sig, t_byte *bit, t_byte *byte, int unsigned *received)
{
	if (sig == SIGUSR1)
	{
		*byte |= 1 << *bit;
		*bit += 1;
	}
	else if (sig == SIGUSR2)
	{
		*byte &= (-1 ^ 1 << *bit);
		*bit += 1;
	}
	if (*bit == 8)
	{
		*received += 1;
		*bit = 0;
	}
}
