/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_receiving.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:57:16 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/07 03:06:00 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	update_byte(int sig, t_byte *bit, t_byte *byte, int unsigned *received)
{
	t_byte	u_bit;
	t_byte	u_byte;

	u_bit = *bit;
	u_byte = *byte;
	ft_dprintf(2, "Bit[%u] of byte[%u]\n", u_bit, *received - 4);
	if (sig == SIGUSR1)
	{
		ft_dprintf(2, "SIGUSR1 received \n");
		u_byte |= 1 << u_bit;
	}
	else if (sig == SIGUSR2)
	{
		ft_dprintf(2, "SIGUSR2 received \n");
		u_byte &= (-1u ^ 1 << u_bit);
	}
	ft_dprintf(2, "After update :\n");
	ft_dprintf(2, "As an integer : %u | as a character : %c\n", u_byte, u_byte);
	u_bit ++;
	if (u_bit == 8)
	{
		*received += 1;
		u_bit = 0;
	}
	*bit = u_bit;
	*byte = u_byte;
}

void	update_length(int sig, t_byte *bit, t_uint *length, t_uint *received)
{
	t_uint	len;
	t_byte	u_bit;

	u_bit = *bit;
	len =  *length;
	if (sig == SIGUSR1)
	{
		ft_dprintf(2, "SIGUSR1 received\n");
		len |= 1 << u_bit;
	}
	else if (sig == SIGUSR2)
	{
		ft_dprintf(2, "SIGUSR2 received\n");
		len &= (-1 ^ 1 << u_bit);
	}
	u_bit ++;
	if (u_bit == 32)
	{
		*received = 4;
		u_bit = 0;
	}
	*bit = u_bit;
	*length = len;
}

void	build_message(int sig, t_message *message)
{
	if (message->bytes < 4)
	{
		ft_dprintf(2, "Updating...\n");
		update_length(sig, &message->bit, &message->length, &message->bytes);
	}
	else if (message->bytes == 4 && ! message->bit && message->message == NULL)
	{
		ft_printf("Size is : %u\n", message->length);
		message->message = ft_calloc(message->length, \
		sizeof * message->message);
		if (message->message == NULL)
			exit(EXIT_FAILURE);
		ft_bzero(message->message, message->length);
		ft_printf("Allocated\n");
		ft_dprintf(2, "Updating after allocation\n");
		update_byte(sig, &message->bit, message->message, &message->bytes);
		//ft_dprintf(2, "Message after allocation");
		//print_tmessage(2, message);
	}
	else if (message->bytes < message->length + 4)
	{
		ft_dprintf(2, "Updating message\n");
		update_byte(sig, &message->bit, \
		message->message + message->bytes - 4, &message->bytes);
		if (message->bit == 0)
		{
			ft_printf("Byte : %d received\n", message->bytes);
			print_tmessage(2, message);
			ft_dprintf(2, "This is the value of the character[%u] in the message\n", message->bytes - 4);
			ft_dprintf(2, "As an integer : %u | And as a character : %c\n", *(message->message + message->bytes - 5), *(message->message + message->bytes - 5));
			print_bits(*(message->message + message->bytes - 5), "1", "0");
			write(2, "\n", 1);
		}
	}
}
