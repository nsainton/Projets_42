/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sending.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:53:19 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/08 03:03:52 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_bit(t_uint bit, pid_t receiver)
{
	if (kill(receiver, 0))
		return (1);
	if (bit)
		kill(receiver, SIGUSR1);
	else
		kill(receiver, SIGUSR2);
	pause();
	return (0);
}

int	send_byte(t_byte byte, pid_t receiver)
{
	t_uint	index;

	index = 0;
	while (index < 7)
	{
		send_bit(byte & 1 << index, receiver);
		index ++;
	}
	return (send_bit(byte & 1 << index, receiver));
}

int	send_integer(t_uint integer, pid_t receiver)
{
	t_uint	index;

	index = 0;
	while (index < 31)
	{
		send_bit(integer & 1 << index, receiver);
		index ++;
	}
	return (send_bit(integer & 1 << index, receiver));
}

int	send_string(t_byte *str, size_t len, pid_t receiver)
{
	size_t	index;

	index = 0;
	if (! len)
		return (0);
	while (index < len - 1)
	{
		send_byte(*(str + index), receiver);
		index ++;
	}
	return (send_byte(*(str + index), receiver));
}
