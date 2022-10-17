/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:06:23 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/17 19:20:38 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read_line(t_buffer *buf, int fd)
{
	ssize_t	n_read;

	if (buf->index < (size_t)buf->n_read)
		return ;
	n_read = read(fd, buf->buffer, BUFF_SIZE);
	write(1, buf->buffer, BUFF_SIZE);
	printf("\n");
	sleep(2);
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

void	ft_fill_line(char *line, t_buffer *buf)
{
	size_t	len;
	size_t	size;
	size_t	start;
	const char	*buffer;

	buffer = buf->buffer;
	if (! (line || buffer))
		return ;
	size = (size_t)buf->n_read;
	len = buf->line_index;
	start = buf->index;
	while (start < size)
	{
		*(line + len) = *(buffer + start);
		len ++;
		if (*(buffer + start) == 10)
			break ;
		start ++;
	}
	buf->index = start + 1;
	buf->line_index = len;
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
	ft_fill_line(*line, buff);
	while (! ft_newline(buff))
	{
		printf("%d\n", ft_newline(buff));
		ft_read_line(buff, fd);
		if (buff->n_read == -1)
		{
			free(*line);
			*line = NULL;
			break ;
		}
		*length = *length + buff->n_read;
		printf("length : %ld\n", *length);
		*line = ft_realloc(*line, *length + 1);
		if (*line == NULL)
			break ;
		ft_fill_line(*line, buff);
	}
}
