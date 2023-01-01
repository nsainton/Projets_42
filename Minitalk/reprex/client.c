/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 21:54:47 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/01 22:50:29 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void    client_handler(int sig, siginfo_t *sigi, void *context)
{
    (void)sigi;
	(void)context;
    if (sig == SIGUSR1)
	    return ;
	exit(EXIT_SUCCESS);
}

void    foo(pid_t receiver)
{
    int i;

	i = 0;
	while (i++ < 200)
	{
	    if (i % 10)
	        kill(receiver, SIGUSR1);
		else
		    kill(receiver, SIGUSR2);
		pause();
	}
}

int main(int ac, char **av)
{
    pid_t            server_pid;
	struct sigaction action;

    if (ac < 2)
	    return (printf("Hello\n"));
	action.sa_sigaction = client_handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	server_pid = atoi(*(av + 1));
	foo(server_pid);
	return (0);
}
