/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 05:24:05 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/30 07:52:43 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

int	main(int ac, char **av)
{
	pid_t				server_pid;
	struct sigaction	action;

	if (ac != 3)
		error_handling("Incorrect number of arguments supplied");
	if (tstr_initstr(&g_message, *(av + 1), 0))
		error_handling("Allocation Error, what did you do to get that?");
	server_pid = ft_atoi(*(av + 1));
	action.sa_sigaction = handle_sigusr2;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &action, NULL);
	if (kill(server_pid, SIGUSR1) == -1)
		error_handling("Why do I talk if no one listens?");
	while (1);
	return (0);
}
