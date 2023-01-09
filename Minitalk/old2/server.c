/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:24:04 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/08 03:25:12 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_sint	g_bit = 0;

void	handle_server(int sig, siginfo_t *sigi, void *context)
{
	(void) context;
	usleep(100);
	if (sig == SIGUSR1)
		g_bit = sigi->si_pid;
	else if (sig == SIGUSR2)
		g_bit = -1 * sigi->si_pid;
	else
		g_bit = 0;
}

void	send_signal(t_message *message, t_sint pid)
{
	if (message->byte.bytes < message->length + 1)
		kill(pid, SIGUSR1);
	else
	{
		write(1, message->message, message->length);
		init_message(message);
		g_bit = 0;
		kill(pid, SIGUSR2);
	}
}

int	main(void)
{
	pid_t		self_pid;
	t_sigaction	action;
	t_message	message;

	self_pid = getpid();
	ft_bzero(&message, sizeof message);
	init_sigaction(&action, handle_server);
	ft_printf("This is my pid : %d\n", self_pid);
	while (1)
	{
		pause();
		update_message(&message, g_bit);
		send_signal(&message, g_bit);
	}
}
