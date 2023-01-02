/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 22:01:08 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/01 22:55:04 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <stdio.h>
# define S1 "SIGUSR1, i equals : "
# define S2 "SIGUSR2, i equals : "

int done = 0;

void    time_consumming_loop(void)
{
    int i;

	i = 0;
	while (i < 1000000)
	{
	    i ++;
		if (i % 10000 == 0)
		    i --;
	}
}

void    print_small_nbr(int nbr)
{
    char c;

    c = (char)nbr;
    if (c < 10)
	{
	    c += 48;
		write(1, &c, 1);
	}
	else
	{
	    print_small_nbr(c / 10);
		print_small_nbr(c % 10);
	}
}

void    server_handler(int sig, siginfo_t *sigi, void *context)
{
	static int  i = 30;

    (void)context;
	if (sig == SIGUSR1)
	{
		i ++;
		write(1, S1, strlen(S1));
		print_small_nbr(i);
		write(1, "\n", 1);
	}
	if (sig == SIGUSR2)
	{
	   i --;
	   write(1, S2, strlen(S2));
	   print_small_nbr(i);
	   write(1, "\n", 1);
	 }
	 time_consumming_loop();
	if (i == 200)
	    done = 1;
	else
	    kill(sigi->si_pid, SIGUSR1);
}

int main(void)
{
    pid_t            pid;
	struct sigaction action;

	pid = getpid();
	printf("This is my pid : %d\n", pid);
    action.sa_sigaction = server_handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (!done) pause();
	return (0);
}
