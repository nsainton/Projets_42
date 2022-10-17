/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agnl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:27:02 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/17 22:10:10 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cgnl.h"

void	ft_read(t_buffer *buff)
{
	ssize_t	n_read;

	n_read = buff->n_read;
	if (n_read < 1)
		return ;
	if (buff->index < (size_t)n_read - 1)
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
			break;
	}
	buffer->line_index = line_index;
	buffer->index = index;
}

char	*ft_realloc(char *str, size_t size)
{
	size_t	i;
	char	*ns;

	if (str == NULL)
		return (NULL);
	ns = (char *)malloc(size * sizeof(char));
	if (ns == NULL)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		*(ns + i) = *(s + i);
		i ++;
	}
	*(ns + i) = 0;
	return (ns);
}

void	ft_getline(char **line, t_buffer *buff)
{
	while (buff->n_read > 0 && *(*line + buff->line_index - 1) != 10)
	{
		ft_read_line(buff);
		if (buff->n_read == -1)
		{
			
