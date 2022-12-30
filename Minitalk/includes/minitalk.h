/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 04:28:56 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/30 07:34:18 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include "../../Libft/includes/libft.h"
# include "ansicolorcodes.h"

extern t_str	g_message;

extern int		g_srv_print;

void			handle_signal(int sig, siginfo_t *sigi, void *context);

void			handle_sigusr1(int sig);

_Noreturn void	handle_sigusr2(int sig, siginfo_t *sigi, void *context);

_Noreturn void	error_handling(char *str);
#endif
