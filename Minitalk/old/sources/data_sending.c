/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sending.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 01:00:28 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/07 05:22:17 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_bit(t_uint bit, pid_t receiver)
{
	if (kill(receiver, 0))
		return (1);
	if (bit)
	{
		ft_dprintf(2, "Sending SIGUSR1\n");
		kill(receiver, SIGUSR1);
	}
	else
	{
		kill(receiver, SIGUSR2);
		ft_dprintf(2, "Sending SIGUSR2\n");
	}
	//pause();
	usleep(1);
	return (0);
}

int	send_byte(t_byte byte, pid_t receiver)
{
	t_uint	bit;

	bit = 0;
	ft_dprintf(2, "This is bit[%d]\n", bit);
	while (bit < 7)
	{
		if (byte & 1 << bit)
			ft_dprintf(2, "This bit is on\n");
		else
			ft_dprintf(2, "This bit is off\n");
		send_bit(byte & 1 << bit, receiver);
		bit ++;
	}
	return (send_bit(byte & 1 << bit, receiver));
}

int	send_integer(t_uint integer, pid_t receiver)
{
	t_uint	bit;

	bit = 0;
//	ft_dprintf(2, "This is byte[%d] : %u\n", bit, 1);
	while (bit < 31)
	{
		send_bit(integer & 1 << bit, receiver);
		bit ++;
	//	ft_dprintf(2, "This is byte[%d] : %u\n", bit, 1 << bit);
	//	ft_dprintf(2, "This is what send_bit saw : %d\n", integer & 1 << (bit - 1));
	}
	return (send_bit(integer & 1 << bit, receiver));
}

int	send_string(t_byte *str, size_t len, pid_t receiver)
{
	size_t	index;

	index = 0;
	if (! len)
		return (0);
	while (index < len - 1)
	{
		ft_dprintf(2, "Sending byte[%u]\n", index);
		send_byte(*(str + index), receiver);
		ft_dprintf(2, "byte[%u] sent\n", index);
		ft_dprintf(2, "These are its bytes\n");
		print_bits(*(str + index), "1", "0");
		write(2, "\n", 1);
		ft_dprintf(2, "Here it is as a char : %c | and as an int : %d\n", *(str + index), *(str + index));
		index ++;
	}
	return(send_byte(*(str + index), receiver));
}
