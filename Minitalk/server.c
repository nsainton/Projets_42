/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:24:04 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/02 05:27:12 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_printed = 0;

void	build_message(int sig, siginfo_t *sigi, void *context)
{
	static t_message	message;

	(void)context;
	//ft_printf("I have been killed with signal : %d\n", sig);
	//ft_printf("This is the bit I'm looking at : %d\n", message.bit);
	//print_bits(message.current_byte);
	if (message.bytes < 4)
		update_byte(sig, &message.bit, (t_byte *)&message.length + message.bytes,&message.bytes);
	else if (message.bytes == 4 && ! message.bit && message.message == NULL)
	{
		ft_printf("This is the length : %u\n", message.length);
		message.message = ft_calloc(message.length, sizeof *message.message);
		if (message.message == NULL)
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		ft_printf("Allocated\n");
		update_byte(sig, &message.bit, message.message, &message.bytes);
	}
	//update_byte(sig, &message.bit, &message.current_byte, &message.bytes);
	//ft_printf("Updated\n");
	//print_bits(message.current_byte);
	//print_bits_integer(message.length, "1", "0");
	//ft_printf("\nThis is the current number of bytes received : %d\n", message.bytes);
	//ft_printf("This is the current watched bit : %d\n", message.bit);
	/*
	if (message.bytes == 4 && ! message.bit)
	{
		//ft_printf("Salut\n");
		ft_printf("This is the length : %u\n", message.length);
		//write(1, &message.current_byte, 1);
		g_printed = 1;
		ft_printf("This is the value of g_printed : %d\n", g_printed);
		kill(sigi->si_pid, SIGUSR2);
		//sleep(1);
	}
	*/
	else if(message.bytes < message.length + 4)
	{
		ft_printf("Updating\n");
		ft_printf("Bytes received : %u\n", message.bytes);
		ft_printf("Current bit : %u\n", message.bit);
		update_byte(sig, &message.bit, message.message + message.bytes - 4, &message.bytes);
	}
	if (message.bytes == message.length + 4)
	{
		ft_printf("Here\n");
		write(1, message.message, message.length);
		init_message(&message);
		g_printed = 1;
		kill(sigi->si_pid, SIGUSR2);
	}
	kill(sigi->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t 				pid;
	t_sigaction			action;

	init_sigaction(&action, build_message);
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
