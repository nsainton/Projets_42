/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 02:20:36 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/05 02:25:23 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H
# include <stdio.h>
# include "libftprintf.h"

void	print_flags(char flags[128]);

void	print_buffer(t_pbuffer *buf);

void	print_pad(t_print *pads);

#endif
