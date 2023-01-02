/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 06:54:35 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/02 06:54:38 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "structures.h"

//Functions from data_sending.c [       5 functions]

int		send_bit(char unsigned bit, pid_t receiver);

int		send_byte(char unsigned byte, pid_t receiver);

int		send_integer(int unsigned quadruplet, pid_t receiver);

void	update_byte(int sig, t_byte *bit, t_byte *byte, int unsigned *received);

void	build_message(int sig, t_message *message);

//Functions from debug.c [       2 functions]

void	print_bits(t_byte byte, char *on, char *off);

void	print_bits_integer(int unsigned to_print, char *on, char *off);

//Functions from init.c [       2 functions]

void	init_sigaction(t_sigaction *action, t_action handler);

void	init_message(t_message *message);

#endif
