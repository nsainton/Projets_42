/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:24:04 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/01 05:59:46 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_printed;

void	build_message(int sig, siginfo_t *sigi, void *context)
{
	static t_message	message;

	(void)sigi;
	(void)context;
	//ft_printf("I have been killed with signal : %d\n", sig);
	//ft_printf("This is the bit I'm looking at : %d\n", message.bit);
	//print_bits(message.current_byte);
	if (message.bytes_received < 4)
		update_byte(sig, &message.bit, (t_byte *)&message.message_length + message.bytes_received,&message.bytes_received);
	//update_byte(sig, &message.bit, &message.current_byte, &message.bytes_received);
	//ft_printf("Updated\n");
	//print_bits(message.current_byte);
	ft_printf("This is the current number of bytes received : %d\n", message.bytes_received);
	ft_printf("This is the current watched bit : %d\n", message.bit);
	if (message.bytes_received == 4 && ! message.bit)
	{
		//ft_printf("Salut\n");
		ft_printf("This is the length : %d\n", message.message_length);
		//write(1, &message.current_byte, 1);
		g_printed = 1;
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
