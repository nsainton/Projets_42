/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_receiving.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:11 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/08 03:30:04 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	update_message(t_message *msg, t_sint signal)
{
	if (! msg->byte.bytes)
		update_length(&msg->length, &msg->byte, signal);
	else if (msg->byte.bytes == 1 && ! msg->byte.bit && msg->message == NULL)
	{
		msg->message = ft_calloc(msg->length, sizeof * msg->message);
		if (msg->message == NULL)
		{
			ft_printf("Error while allocating\n");
			exit(EXIT_FAILURE);
		}
		update_byte(msg->message, &msg->byte, signal);
	}
	else if (msg->byte.bytes < msg->length + 1)
		update_byte(msg->message, &msg->byte, signal);
}

void	update_length(t_uint *length, t_byte_count *count, t_sint signal)
{
	t_uint	len;
	t_byte	bit;

	len = *length;
	bit = count->bit;
	if (signal > 0)
		len |= 1 << bit;
	else
		len &= (-1 ^ 1 << bit);
	bit ++;
	if (bit == 32)
	{
		bit = 0;
		count->bytes = 1;
	}
	*length = len;
	count->bit = bit;
}

void	update_byte(t_byte *message, t_byte_count *count, t_sint signal)
{
	t_byte	bit;
	t_byte	msg;

	msg = *(message + count->bytes - 1);
	bit = count->bit;
	if (signal > 0)
		msg |= 1 << bit;
	else
		msg &= (-1 ^ 1 << bit);
	*(message + count->bytes - 1) = msg;
	bit ++;
	if (bit == 8)
	{
		bit = 0;
		count->bytes += 1;
	}
	count->bit = bit;
}
