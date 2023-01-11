/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_receiving.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaintON <nsaintON@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 03:03:53 by nsaintON          #+#    #+#             */
/*   Updated: 2023/01/12 00:41:49 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	update_message(pid_t receiver, int signal)
{
	static t_message	message;

	if (! signal)
	{
		init_message(&message);
		update_length(0, NULL, NULL, 0);
		update_byte(NULL, NULL, 0);
		return (0);
	}
	if (! message.length)
		return (update_length(receiver, &message.len, \
		&message.length, signal));
	return (update_string(receiver, &message, signal));
}

int	update_length(pid_t receiver, size_t *length, t_byte *received, int signal)
{
	static int	bit;

	if (! signal)
	{
		bit = 0;
		return (0);
	}
	if (signal == ON)
		*length |= 1 << bit++;
	else
		*length &= (-1 ^ 1 << bit++);
	if (bit == 32)
	{
		*received = 1;
		bit = 0;
	}
	return (kill(receiver, CONTINUE));
}

int	update_string(pid_t receiver, t_message *message, int signal)
{
	if (message->str == NULL)
	{
		message->str = ft_calloc(message->len, sizeof * message->str);
		if (message->str == NULL)
		{
			ft_printf("error while allocating\n");
			kill(receiver, CONTINUE);
			exit(EXIT_FAILURE);
		}
		update_byte(message->str, &message->bytes, signal);
	}
	else if (message->bytes < message->len)
		update_byte(message->str, &message->bytes, signal);
	if (message->bytes == message->len)
	{
		print_message(message);
		update_message(0, 0);
		return (kill(receiver, RECEIVED));
	}
	return (kill(receiver, CONTINUE));
}

void	update_byte(t_byte *msg, t_uint *bytes, int signal)
{
	static int	bit;

	if (! signal)
		bit = 0;
	else if (signal == ON)
		*(msg + *bytes) |= 1 << bit ++;
	else if (signal == OFF)
		*(msg + *bytes) &= (-1 ^ 1 << bit ++);
	if (bit == 8)
	{
		*bytes += 1;
		bit = 0;
	}
}
