/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 05:24:05 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/30 06:46:17 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

int	main(int ac, char **av)
{
	pid_t				server_pid;
	struct sigaction	action;

	if (ac != 3)
	{
		ft_printf("%sIncorrect number of arguments supplied%s\n", RED,\
		CRESET);
		exit(EXIT_FAILURE);
	}
	g_message = *(av + 2);
	server_pid = ft_atoi(*(av + 1));
	action.sa_sigaction = handle_sigusr2;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &action, NULL);
	if (kill(server_pid, SIGUSR1) == -1)
	{
		ft_printf("%sWhy do I talk if no one listens?%s\n", RED, CRESET);
		exit(EXIT_FAILURE);
	}
	while (1);
	return (0);
}
