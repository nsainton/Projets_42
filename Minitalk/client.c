/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:08:58 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/07 03:26:14 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_client(int sig, siginfo_t *sigi, void *context)
{
	(void)sigi;
	(void)context;
	if (sig == SIGUSR1)
	{
		ft_dprintf(2, "SIGUSR1 received\n");
		return ;
	}
	else if (sig == SIGUSR2)
	{
		ft_dprintf(2, "SIGUSR2 received\n");
		ft_printf("The server acknowledges the successful \
	reception of the message\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int ac, char **av)
{
	pid_t		receiver;
	size_t		len;
	t_sigaction	action;

	init_sigaction(&action, handle_client);
	if (ac != 3)
		return (ft_printf("Bonjour\n"));
	receiver = ft_atoi(*(av + 1));
	if (receiver < 1)
		return (ft_printf("Error\n"));
	len = ft_strlen(*(av + 2));
	if (send_integer(len, receiver))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	ft_dprintf(2, "This is the len : %u\n", len);
	print_bits_integer(len, "1", "0");
	send_string((t_byte *)*(av + 2), len, receiver);
	return (0);
}
