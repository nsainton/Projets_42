/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sending.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 01:00:28 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/01 01:00:58 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	send_bit(char unsigned bit, pid_t receiver)
{
	if (bit && ! kill(receiver, SIGUSR1))
		return (0);
	else if (!bit && ! kill(receiver, SIGUSR2))
		return (0);
	return (1);
}

int	send_byte(char unsigned byte, pid_t receiver)
{
	int unsigned			i;
	int						t;
	static struct sigaction	info;

	i = 0;
	while (i < 7)
	{
		t = send_bit(byte & 1 << i, receiver);
		//ft_printf("This is the return value for bit[%d] : %d\n", i, t);
		i ++;
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