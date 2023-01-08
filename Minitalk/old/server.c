/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:24:04 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/07 05:24:10 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bit = 0;

void	print_message(int sig, siginfo_t *sigi, void *context)
{
	(void)context;
	(void)sigi;
	/*
	print_bits_integer(message.length, "1", "0");
	write(2, "\n", 1);
	if (message.bytes == 4)
	{
		ft_printf("Length : %u\n", message.length);
	}
	*/
	if (sig == SIGUSR1)
		g_bit = 1;
	else
		g_bit = 0;
}

int	main(void)
{
	pid_t		pid;
	t_sigaction	action;
	t_message	message;

	init_sigaction(&action, print_message);
	pid = getpid();
	ft_printf("This is my pid : %d\n", pid);
	while (1)
	{
	pause();
	build_message(g_bit, &message);
	/*
	print_bits_integer(message.length, "1", "0");
	write(2, "\n", 1);
	if (message.bytes == 4)
	{
		ft_printf("Length : %u\n", message.length);
	}
	*/
	if (message.bytes > 4 && message.bytes == message.length + 4)
	{
		sleep(1);
		write(1, message.message, message.length);
		init_message(&message);
		g_bit = 2;
		ft_dprintf(2, "Sending back SIGUSR2\n");
		//kill(sigi->si_pid, SIGUSR2);
	}
	else
	{
		ft_dprintf(2, "Sending back SIGUSR1\n");
		//kill(sigi->si_pid, SIGUSR1);
	}

	}
	return (0);
}
