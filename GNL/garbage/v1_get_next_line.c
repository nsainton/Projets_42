/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:22:22 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/17 21:25:41 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_next_line(int fd)
{
	static t_buffer	buff = {{0}, BUFF_SIZE, BUFF_SIZE, 0};
	char			*line;
	size_t			length;

	ft_read_line(&buff, fd);
	if (buff.n_read < 1)
		return (NULL);
	line = (char *)malloc((buff.n_read + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	length = buff.n_read + 1;
	*line = 0;
	ft_getline(&line, &buff, &length, fd);
	if (line == NULL)
		return (NULL);
	line = ft_realloc(line, buff.line_index);
	buf->line_index = 0;
	return (line);
}

int	ft_newline(t_buffer *buf)
{
	size_t		i;
	size_t		n_read;
	const char	*buffer;

	i = buf->index;
	buffer = buf->buffer;
	n_read = (size_t)buf->n_read;
	printf("index : %ld, n_read : %ld\n", i, n_read);
	while (i < n_read)
	{
		if (*(buffer + i) == 10)
			return (1);
		i ++;
	}
	if ( (n_read && buffer[n_read] - 1 == 10) || ! n_read)
		return (1);
	return (0);
}
