/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 04:28:56 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/30 06:12:01 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include "../../Libft/includes/libft.h"
# include "ansicolorcodes.h"

extern char	*g_message;

extern int	g_srv_print;

void	handle_signal(int sig, siginfo_t *sigi, void *context);

void	handle_sigusr1(int sig);

_Noreturn void	handle_sigusr2(int sig, siginfo_t *sigi, void *context);

#endif
