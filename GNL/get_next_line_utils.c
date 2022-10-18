/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:27:02 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/18 20:13:19 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

void	ft_read(t_buffer *buff, int fd)
{
	ssize_t	n_read;

	n_read = buff->n_read;
	if (n_read < 1)
		return ;
	if (buff->index < (size_t)n_read)
		return ;
	n_read = read(fd, buff->buffer, BUFF_SIZE);
	buff->n_read = n_read;
	buff->index = 0;
}

void	ft_fill_line(char *line, t_buffer *buff)
{
	size_t		line_index;
	size_t		index;
	size_t		n_read;
	const char	*buffer;

	n_read = (size_t)buff->n_read;
	index = buff->index;
	line_index = buff->line_index;
	buffer = buff->buffer;
	while (index < n_read)
	{
		*(line + line_index) = *(buffer + index);
		line_index ++;
		index ++;
		if (*(buffer + index - 1) == 10)
			break ;
	}
	buff->line_index = line_index;
	buff->index = index;
}

char	*ft_realloc(char *str, size_t size)
{
	size_t	i;
	char	*ns;

	if (str == NULL)
		return (NULL);
	ns = (char *)malloc((size + 1) * sizeof(char));
	if (ns == NULL)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		*(ns + i) = *(str + i);
		i ++;
	}
	*(ns + i) = 0;
	free(str);
	return (ns);
}

char	*ft_get_line(char *line, t_buffer *t_buff, int fd, size_t *length)
{
	ft_read(t_buff, fd);
	while (t_buff->n_read > 0)
	{
		*length = *length + (size_t)t_buff->n_read;
		line = ft_realloc(line, *length);
		if (line == NULL)
			break ;
		ft_fill_line(line, t_buff);
		if (*(line + t_buff->line_index - 1) == 10)
		{
			break ;
		}
		ft_read(t_buff, fd);
	}
	if (t_buff->n_read == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

void	ft_reinit(t_buffer *t_buff)
{
	if (t_buff == NULL)
		return ;
	t_buff->n_read = BUFF_SIZE;
	t_buff->index = BUFF_SIZE;
	t_buff->line_index = 0;
}
