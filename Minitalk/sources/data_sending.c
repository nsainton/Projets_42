/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sending.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 01:00:28 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/06 20:27:42 by nsainton         ###   ########.fr       */
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
	int unsigned			i;
	int						t;

	i = 0;
	ft_dprintf(2, "This is byte[%d]\n", i);
	while (i < 7)
	{
		t = send_bit(byte & 1 << i, receiver);
		i ++;
		ft_dprintf(2, "This is byte[%d]\n", i);
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
	t_byte	u_bit;
	t_byte	u_byte;

	u_bit = *bit;
	u_byte = *byte;
	if (sig == SIGUSR1)
		u_byte |= 1 << u_bit;
	else if (sig == SIGUSR2)
		u_byte &= (-1 ^ 1 << u_bit);
	u_bit ++;
	if (u_bit == 8)
	{
		*received += 1;
		u_bit = 0;
	}
	*bit = u_bit;
	*byte = u_byte;
}

void	build_message(int sig, t_message *message)
{
	if (message->bytes < 4)
		update_byte(sig, &message->bit, \
		(t_byte *)&message->length + message->bytes, &message->bytes);
	else if (message->bytes == 4 && ! message->bit && message->message == NULL)
	{
		ft_printf("Size is : %u\n", message->length);
		message->message = ft_calloc(message->length, \
		sizeof * message->message);
		if (message->message == NULL)
			exit(EXIT_FAILURE);
		ft_bzero(message->message, message->length);
		ft_printf("Allocated\n");
		update_byte(sig, &message->bit, message->message, &message->bytes);
		//ft_dprintf(2, "Message after allocation");
		print_tmessage(2, message);
	}
	else if (message->bytes < message->length + 4)
	{
		update_byte(sig, &message->bit, \
		message->message + message->bytes - 4, &message->bytes);
		if (message->bit == 0)
		{
			ft_printf("Byte : %d received\n", message->bytes);
			print_tmessage(2, message);
		}
	}
}
