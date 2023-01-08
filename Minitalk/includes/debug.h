/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:42:30 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/08 03:29:46 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H
# include "structures.h"

void	print_bits(t_byte byte, char *on, char *off);

void	print_bits_integer(int unsigned to_print, char *on, char *off);

void	print_tmessage(int fd, t_message *message);

#endif
