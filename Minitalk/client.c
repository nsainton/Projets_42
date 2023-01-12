/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 23:42:36 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/12 03:17:38 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_client(int sig, siginfo_t *sigi, void *context)
{
	(void)context;
	usleep(50);
	if (sig == RECEIVED)
	{
		ft_printf("The server acknowledges the successful \
reception of the message\n");
		exit(EXIT_SUCCESS);
	}
	if (send_string(sigi->si_pid, NULL))
	{
		ft_printf("Error !\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	t_sigaction	action;
	pid_t		server_pid;

	if (ac != 3)
	{
		ft_printf("Incorrect number of arguments\n");
		return (1);
	}
	server_pid = (pid_t)ft_atoi(av[1]);
	if (server_pid < 1)
	{
		ft_printf("Server PID must me positive\n");
		return (2);
	}
	if (**(av + 2) == 0)
		return (0);
	init_sigaction(&action, handle_client);
	send_string(server_pid, (t_byte *)*(av + 2));
	while (1)
		pause();
	return (0);
}
