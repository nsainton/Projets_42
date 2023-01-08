/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:05:51 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/08 03:06:01 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "structures.h"

//Functions from data_receiving.c [       3 functions]

void	update_message(t_message *msg, t_sint signal);

void	update_length(t_uint *length, t_byte_count *count, t_sint signal);

void	update_byte(t_byte *message, t_byte_count *count, t_sint signal);

//Functions from data_sending.c [       4 functions]

int		send_bit(t_uint bit, pid_t receiver);

int		send_byte(t_byte byte, pid_t receiver);

int		send_integer(t_uint integer, pid_t receiver);

int		send_string(t_byte *str, size_t len, pid_t receiver);

//Functions from debug.c [       3 functions]

void	print_bits(t_byte byte, char *on, char *off);

void	print_bits_integer(int unsigned integer, char *on, char *off);

void	print_tmessage(int fd, t_message *message);

//Functions from init.c [       2 functions]

void	init_sigaction(t_sigaction *action, t_action handler);

void	init_message(t_message *message);

#endif
