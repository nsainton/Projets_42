/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:06:23 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/17 14:16:19 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_putstr(char *str)
{
	if (str == NULL)
		return ;
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	ft_read_line(t_buffer *buf, int fd)
{
	ssize_t	n_read;

	ft_putstr("Read_line");
	sleep(3);
	if (buf->index < (size_t)buf->n_read)
		return ;
	n_read = read(fd, buf->buffer, BUFF_SIZE);
	buf->n_read = n_read;
	buf->index = 0;
}

size_t	ft_strlen(const char *s)
{
	const char	*ptr;

	if (s == NULL)
		return (0);
	ptr = s;
	while (*ptr)
		ptr ++;
	return (ptr - s);
}

size_t	ft_fill_line(char *line, const char *buffer, size_t start, size_t size)
{
	size_t	len;
	size_t	i;

	ft_putstr("fill_line");
	if (! (line || buffer))
		return (0);
	len = ft_strlen(line);
	i = start;
	while (start < size)
	{
		*(line + len) = *(buffer + start);
		if (*(buffer + start) == 10)
			break ;
		len ++;
		start ++;
	}
	buff->index = start;
	return (start - i);
}

char	*ft_realloc(char *line, size_t final_length)
{
	char	*ns;
	size_t	i;

	if (line == NULL)
		return (NULL);
	ns = (char *)malloc((final_length + 1) * sizeof(char));
	if (ns == NULL)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (i < final_length)
	{
		*(ns + i) = *(line + i);
		i ++;
	}
	*(ns + i) = 0;
	free(line);
	return (ns);
}

void	ft_getline(char **line, t_buffer *buff, size_t *length, int fd)
{
	size_t	chars_added;

	chars_added = ft_fill_line(*line, buff->buffer, buff->index, (size_t)buff->n_read);
	while (chars_added == (size_t)buff->n_read)
	{
		ft_read_line(buff, fd);
		write(1, buff->buffer, buff->n_read);
		sleep(3);
		if (buff->n_read == -1)
		{
			free(*line);
			*line = NULL;
			break ;
		}
		*length = *length + buff->n_read;
		*line = ft_realloc(*line, *length);
		if (*line == NULL)
			break ;
		chars_added = ft_fill_line(*line, buff->buffer, buff->index, (size_t)buff->n_read);
	}
}
