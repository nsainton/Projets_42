/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sending.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 01:00:28 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/05 17:49:36 by nsainton         ###   ########.fr       */
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

void	update_byte(int sig, t_byte *bit, t_byte *byte, int unsigned *received)
{
	*byte = *byte * (*bit > 0);
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
		ft_printf("Allocated\n");
		update_byte(sig, &message->bit, message->message, &message->bytes);
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
