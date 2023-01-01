/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:08:58 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/01 18:27:28 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_sent;

void	handle_client(int sig, siginfo_t *sigi, void *context)
{
	(void)sigi;
	(void)context;
	if (sig == SIGUSR1)
		return ;
	g_sent = 1;
}

int	main(int ac, char **av)
{
	int					i;
	int					test;
	pid_t				receiver;
	t_sigaction			action;

	init_sigaction(&action, handle_client);
	if (ac != 3)
		return (ft_printf("Bonjour\n"));
	receiver = ft_atoi(*(av + 1));
	if (receiver < 1)
		return (ft_printf("Error\n"));
	test = ft_atoi(*(av + 2));
	i = send_integer(test, receiver);
	//print_bits(**(av + 2));
	ft_printf("This is the test integer : %d\n", test);
	ft_printf("And these are its bits : ");
	print_bits_integer(test);
	ft_printf("\nThis is the server pid : %d\n", receiver);
	ft_printf("This is the return value : %d\n", i);
	return (0);
}
