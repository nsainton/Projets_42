/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:08:58 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/01 07:41:53 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_client(int sig, siginfo_t *sigi, void *context)
{
	(void)sig;
	(void)sigi;
	(void)context;
	return ;
}

int	main(int ac, char **av)
{
	int					i;
	pid_t				receiver;
	t_sigaction			action;

	init_sigaction(&action, handle_client);
	if (ac != 3)
		return (ft_printf("Bonjour\n"));
	receiver = ft_atoi(*(av + 1));
	if (receiver < 1)
		return (ft_printf("Error\n"));
	i = send_integer(9324, receiver);
	//print_bits(**(av + 2));
	ft_printf("This is the server pid : %d\n", receiver);
	ft_printf("This is the return value : %d\n", i);
	return (0);
}
