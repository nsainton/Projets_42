/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 06:09:30 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/30 07:57:33 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_str	g_message = {0};

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
	ft_printf("1\n");
	tstr_print(&g_message);
	free(g_message.str);
	tstr_init(&g_message);
}

_Noreturn void	handle_sigusr2(int sig, siginfo_t *sigi, void *context)
{
	(void)context;
	(void)sig;
	ft_printf("The server at %s%d%s acknowledges that it received the \
message", GRN, (int)sigi->si_pid, CRESET);
	exit(EXIT_SUCCESS);
}

_Noreturn void	error_handling(char *str)
{
	ft_printf("%s%s%s\n", RED, str, CRESET);
	exit(EXIT_FAILURE);
}
