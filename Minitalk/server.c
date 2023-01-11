/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 02:03:53 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/12 00:42:30 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_server(int sig, siginfo_t *sigi, void *context)
{	
	(void)context;
	usleep(50);
	if (update_message(sigi->si_pid, sig))
	{
		update_message(0, 0);
		ft_printf("Error\n");
	}
}

int	main(void)
{
	t_sigaction	action;
	pid_t		pid;

	init_sigaction(&action, handle_server);
	pid = getpid();
	ft_printf("This is my pid : %d\n", pid);
	while (1)
		pause();
	return (0);
}
