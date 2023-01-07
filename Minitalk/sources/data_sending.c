/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sending.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 01:00:28 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/07 01:57:45 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_bit(char unsigned bit, pid_t receiver)
{
	if (kill(receiver, 0))
		return (1);
	if (bit)
	{
//		ft_dprintf(2, "Sending SIGUSR1\n");
		kill(receiver, SIGUSR1);
	}
	else
	{
		kill(receiver, SIGUSR2);
//		ft_dprintf(2, "Sending SIGUSR2\n");
	}
	pause();
	return (0);
}

int	send_byte(char unsigned byte, pid_t receiver)
{
	int unsigned			bit;

	bit = 0;
//	ft_dprintf(2, "This is byte[%d]\n", i);
	while (bit < 7)
	{
		send_bit(byte & 1 << bit, receiver);
		bit ++;
//		ft_dprintf(2, "This is byte[%d]\n", i);
	}
	return (send_bit(byte & 1 << bit, receiver));
}

int	send_integer(int unsigned integer, pid_t receiver)
{
	int unsigned	bit;

	bit = 0;
	while (bit < 31)
	{
		send_bit(integer & 1 << bit, receiver);
		bit ++;
	}
	return (send_bit(integer & 1 << bit, receiver));
}
