/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 04:56:00 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/13 04:44:38 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H
# include "get_next_line.h"

void	print_buffer(char buf[BUFFER_SIZE + 1]);

void	print_line(t_gline *line);
#endif
