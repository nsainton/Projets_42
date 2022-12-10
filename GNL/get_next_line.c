/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:11:30 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/10 05:11:15 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "debug.h"

static int	parse_line(t_gline *line, char buf[BUFFER_SIZE + 1], const size_t bytes)
{
	size_t	index;
	char	*parser;

	index = 0;
	parser = line->line + line->line_index;
	while (index < bytes)
	{
		if (*(parser + index) == '\n')
		{
			ft_memmove(buf, parser + index + 1, bytes - index + 1);
			*(parser + index + 1) = 0;
			line->line_index += index;
			return (1);
		}
		index ++;
	}
	line->line_index += index;
	return (0);
}

static int	fill_line(t_gline *line, char buf[BUFFER_SIZE + 1])
{
	size_t	l_index;
	size_t	b_index;

	l_index = line->line_index;
	b_index = 0;
	while (b_index < BUFFER_SIZE && buf[b_index])
	{
		*(line->line + l_index) = buf[b_index];
		if(buf[b_index] == '\n')
		{
			*(line->line + l_index + 1) = 0;
			write(1, "Avant modif : \n",15);
			print_buffer(buf);
			ft_memmove(buf, buf + b_index + 1, BUFFER_SIZE - b_index - 1);
			ft_bzero(buf + BUFFER_SIZE - b_index - 1, b_index + 1);
			write(1, "Apres modif : \n",15); 
			print_buffer(buf);
			sleep(1);
			line->line_index = l_index + 1;
			return (1);
		}
		l_index ++;
		b_index ++;
	}
	return (0);
}

static int	read_line(t_gline *line, char buf[BUFFER_SIZE + 1], const int fd)
{
	ssize_t	n_read;

	n_read = read(fd, line->line + line->line_index, BUFFER_SIZE);
	while (n_read > 0)
	{
		if (parse_line(line, buf, (const size_t)n_read))
			return (1);
		line->line = ft_realloc(line->line, line->line_index + 1, line->line_index + BUFFER_SIZE + 1);
		if (line->line == NULL)
			return (0);
		n_read = read(fd, line->line + line->line_index, BUFFER_SIZE);
	}
	return (ft_check_line(buf, line->line, n_read));
}

char	*get_next_line(int fd)
{
	static char	buf[FILES][BUFFER_SIZE + 1];
	t_gline		line;

	if (fd < 0 || fd > FILES - 1)
		return (NULL);
	if (buf[fd][BUFFER_SIZE])
		return (NULL);
	line.line = malloc(sizeof *(line.line) * (BUFFER_SIZE + 1));
	if (line.line == NULL)
		return (NULL);
	line.line_index = 0;
	*(line.line) = 0;
	if (fill_line(&line, buf[fd]))
		return (ft_realloc(line.line, line.line_index + 1, BUFFER_SIZE + 1));
	if (read_line(&line, buf[fd], fd))
		return (ft_realloc(line.line, line.line_index + 1, line.line_index + 1));
	return (NULL);
}
