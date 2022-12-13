/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 04:57:49 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/13 04:44:40 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_buffer(char buf[BUFFER_SIZE + 1])
{
	size_t	i;

	write(1, "BUFFER\n", 7);
	i = 0;
	while (buf[i])
	{
		if (buf[i] != '\n')
			write(1, buf + i, 1);
		else
			write(1, "_", 1);
		i ++;
	}
	write(1, "\n", 1);
}

void	print_line(t_gline *line)
{
	write(1, "LINE\n", 5);
	write(1, line->line, line->line_index);
	write(1, "\n", 1);
}
