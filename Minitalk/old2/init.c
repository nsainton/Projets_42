/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 07:34:17 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/08 03:28:28 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	init_sigaction(t_sigaction *action, t_action handler)
{
	ft_bzero(action, sizeof * action);
	action->sa_sigaction = handler;
	action->sa_flags = SA_SIGINFO;
	sigemptyset(&action->sa_mask);
	sigaddset(&action->sa_mask, SIGUSR1);
	sigaddset(&action->sa_mask, SIGUSR2);
	sigaction(SIGUSR1, action, NULL);
	sigaction(SIGUSR2, action, NULL);
}

void	init_message(t_message *message)
{
	if (message->message != NULL)
	{
		ft_dprintf(2, "This is the message : \n");
		write(2, message->message, message->length);
		free(message->message);
		ft_dprintf(2, "Message freed\n", 1);
	}
	ft_bzero(message, sizeof * message);
}
