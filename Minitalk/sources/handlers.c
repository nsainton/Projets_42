/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 06:09:30 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/30 06:50:56 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

char	*g_message = NULL;

int		g_srv_print = 0;

void	handle_signal(int sig, siginfo_t *sigi, void *context)
{
	(void)context;
	(void)sig;
	handle_sigusr1(sig);
	if (kill(sigi->si_pid, SIGUSR2) == -1)
	{
		ft_printf("A mysterious and unexpected error occured\n");
		exit(EXIT_FAILURE);
	}
	g_srv_print = 1;
}

void	handle_sigusr1(int sig)
{
	(void)sig;
	ft_printf("%s", g_message);
}

_Noreturn void	handle_sigusr2(int sig, siginfo_t *sigi, void *context)
{
	(void)context;
	(void)sig;
	ft_printf("The server at %s%d%s acknowledges that it received the \
message", GRN, (int)sigi->si_pid, CRESET);
	exit(EXIT_SUCCESS);
}

