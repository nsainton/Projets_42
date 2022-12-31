/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 04:27:30 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/30 21:49:49 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static void	srv_start(void)
{
	int	pid;

	pid = (int)getpid();
	ft_printf("%s      #######                                        \
	\n\
    /       ###                                                       \n\
   /         ##                                                       \n\
   ##        #                      ##                                \n\
    ###                             ##                                \n\
   ## ###           /##  ###  /###   ##    ###      /##  ###  /###    \n\
    ### ###        / ###  ###/ #### / ##    ###    / ###  ###/ #### / \n\
      ### ###     /   ###  ##   ###/  ##     ###  /   ###  ##   ###/  \n\
        ### /##  ##    ### ##         ##      ## ##    ### ##         \n\
          #/ /## ########  ##         ##      ## ########  ##         \n\
           #/ ## #######   ##         ##      ## #######   ##         \n\
            # /  ##        ##         ##      ## ##        ##         \n\
  /##        /   ####    / ##         ##      /  ####    / ##         \n\
 /  ########/     ######/  ###         ######/    ######/  ###        \n\
/     #####        #####    ###         #####      #####    ###       \n\
|                                                                     \n\
                                                                      %s\n", \
	GRN, CRESET);
	ft_printf("%sListening at : %s%d\n", BLU, CRESET, pid);
}

int	main(void)
{
	srv_start();
	struct sigaction	action;

	action.sa_sigaction = handle_signal;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &action, NULL);
	while (1)
	{
		while (! g_srv_print)
		{
			sleep(1);
		}
		g_srv_print = 0;
	}
}
