/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:08:58 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/31 23:48:27 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	int unsigned	i;
	int				t;

	i = 0;
	while (i < 7)
	{
		t = send_bit(byte & 1 << i, receiver);
		//ft_printf("This is the return value for bit[%d] : %d\n", i, t);
		i ++;
		usleep(100);
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

int	main(int ac, char **av)
{
	int		i;
	pid_t	receiver;

	if (ac != 3)
		return (ft_printf("Bonjour\n"));
	receiver = ft_atoi(*(av + 1));
	if (receiver < 1)
		return (ft_printf("Error\n"));
	i = send_integer(9324, receiver);
	//print_bits(**(av + 2));
	ft_printf("This is the server pid : %d\n", receiver);
	ft_printf("This is the return value : %d\n", i);
	return (0);
}
