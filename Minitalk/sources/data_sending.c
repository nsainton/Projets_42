/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sending.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 03:17:08 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/12 00:40:45 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_string(pid_t receiver, t_byte *str)
{
	static t_string_infos	to_send;

	if (str)
		to_send.str = str;
	if (! to_send.len)
		to_send.len = ft_strlen((char *)str);
	if (! to_send.len_sent)
		return (send_len(receiver, to_send.len, &to_send.len_sent));
	if (*to_send.str)
	{
		if (to_send.bit == 8)
		{
			to_send.bit = 0;
			to_send.str ++;
		}
		if (*to_send.str & 1 << to_send.bit++)
			return (kill(receiver, ON));
		else
			return (kill(receiver, OFF));
	}
	else
		return (kill(receiver, ON));
}

int	send_len(pid_t receiver, size_t len, t_byte *sent)
{
	static int	bit;
	int			killed;

	if (len & 1 << bit++)
		killed = kill(receiver, ON);
	else
		killed = kill(receiver, OFF);
	if (bit == 32)
	{
		*sent = 1;
		bit = 0;
	}
	return (killed);
}
