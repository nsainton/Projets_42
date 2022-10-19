/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:45:07 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/19 23:01:14 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_flush(char **buff, size_t start, int fd)
{
	size_t	index;

	index = start;
	while (index < BUFF_SIZE)
	{
		*(*(buff + fd) + index - start) = *(*(buff + fd) + index);
		index ++;
	}
}

static void	ft_fill_line(char *line, char **buff, int fd, size_t *end_of_line)
{
	size_t	buffer_index;
	size_t	line_index;

	buffer_index = 0;
	line_index = *end_of_line;
	while (buffer_index < BUFF_SIZE && *(*(buff + fd) + buffer_index))
	{
		*(line + line_index) = *(*(buff + fd) + buffer_index);
		buffer_index ++;
		line_index ++;
		if (*(*(buff + fd) + buffer_index - 1) == 10)
			break ;
	}
	ft_flush(buff, buffer_index, fd);
	*end_of_line = line_index;
}

static char	*ft_realloc(char *str, size_t size)
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

char	*ft_get_line(char *line, char **buff, int fd, size_t *line_index)
{
	ssize_t	n_read;

	n_read = read(fd, (void *)*(buff + fd), BUFF_SIZE);
	while (n_read > 0)
	{
		line = ft_realloc(line, *line_index + (size_t)n_read);
		if (line == NULL)
			break ;
		ft_fill_line(line, buff, fd, line_index);
		if (*(line + *line_index - 1) == 10)
			break ;
		n_read = read(fd, (void *)*(buff + fd), BUFF_SIZE);
	}
	if (n_read == -1)
	{
		free(line);
		return (NULL);
	}
	return (ft_realloc(line, *line_index));
}
