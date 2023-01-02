/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:08:58 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/02 05:27:36 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_sent;

void	handle_client(int sig, siginfo_t *sigi, void *context)
{
	(void)sigi;
	(void)context;
	if (sig == SIGUSR1)
		return ;
	//ft_printf("\nData sent\n");
	//g_sent = 1;
	ft_printf("The server acknowledges the successfull recepetion of the message\n");
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	pid_t				receiver;
	size_t				len;
	size_t				index;
	t_sigaction			action;

	init_sigaction(&action, handle_client);
	if (ac != 3)
		return (ft_printf("Bonjour\n"));
	receiver = ft_atoi(*(av + 1));
	if (receiver < 1)
		return (ft_printf("Error\n"));
	len = ft_strlen(*(av + 2));
	//ft_printf("This is the test integer : %d\n", test);
	//ft_printf("And these are its bits : ");
	//print_bits_integer(test, "1", "0");
	if (send_integer(len, receiver))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	index = 0;
	while (index < len)
	{
		send_byte((t_byte)*(*(av + 2) + index), receiver);
		index ++;
	}
	//kill(receiver, SIGUSR1);
	/*
	print_bits(**(av + 2));
	ft_printf("\nThis is the server pid : %d\n", receiver);
	ft_printf("This is the return value : %d\n", i);
	*/
	return (0);
}
