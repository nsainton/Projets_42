/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:24:04 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/04 01:21:36 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_printed = 0;

void	print_message(int sig, siginfo_t *sigi, void *context)
{
	static t_message	message;

	(void)context;
	usleep(10);
	build_message(sig, &message);
	if (message.bytes == message.length + 4)
	{
		sleep(1);
		write(1, message.message, message.length);
		init_message(&message);
		g_printed = 1;
		kill(sigi->si_pid, SIGUSR2);
	}
	kill(sigi->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t		pid;
	t_sigaction	action;

	init_sigaction(&action, print_message);
	pid = getpid();
	ft_printf("This is my pid : %d\n", pid);
	while (1)
	{
		while (!g_printed)
			pause();
		g_printed = 0;
	}
	return (0);
}
