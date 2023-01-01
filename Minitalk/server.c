/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:24:04 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/01 01:30:58 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

int	g_printed;

void	update_byte(int sig, t_byte *bit, t_byte *byte, int unsigned *received)
{
	if (sig == SIGUSR1)
	{
		*byte |= 1 << *bit;
		*bit += 1;
	}
	else if (sig == SIGUSR2)
	{
		*byte &= (-1 ^ 1 << *bit);
		*bit += 1;
	}
	if (*bit == 8)
	{
		*received += 1;
		*bit = 0;
	}
}

int	main(void)
{
	pid_t 				pid;
	struct sigaction	action;

	action.sa_sigaction = build_message;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	pid = getpid();
	ft_printf("This is my pid : %d\n", pid);
	while (!g_printed);
	return (0);
}
