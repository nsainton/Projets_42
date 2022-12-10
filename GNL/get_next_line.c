/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:11:30 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/08 07:39:19 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	parse_line(t_gline *line, const size_t bytes)
{
	size_t	index;
	char	*line;

	index = 0;
	line = buf->line_index;
	while (index < bytes)
	{
		if (*(line + index) == '\n')
		{
			ft_memmove(buf, line + index + 1, bytes - index + 1);
			*(line + index + 1) = 0;
			return (1);
		}
		index ++;
	}
	return (0);
}

int	read_line(t_gline *line, const int fd)
{
	ssize_t	n_read;

	n_read = read(fd, line->line + line->line_index, BUFFER_SIZE);
