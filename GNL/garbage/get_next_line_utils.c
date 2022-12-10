/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:28:13 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/10 17:03:59 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_flush(char buff[BUFF_SIZE], size_t index)
{
	size_t	i;

	i = index;
	while (i < BUFF_SIZE)
	{
		buff[i - index] = buff[i];
		i ++;
	}
	i = BUFF_SIZE - index;
	while (i < BUFF_SIZE)
	{
		buff[i] = 0;
		i ++;
	}
}

static char	*ft_realloc(char *str, size_t size, size_t base_size)
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
	while (i < base_size)
	{
		*(ns + i) = *(str + i);
		i ++;
	}
	*(ns + i) = 0;
	free(str);
	return (ns);
}

static int	ft_fill_line(char *line, char buff[BUFF_SIZE], size_t *end_of_line)
{
	size_t	line_index;
	size_t	buffer_index;
	int		new_line;

	line_index = *end_of_line;
	buffer_index = 0;
	new_line = 0;
	while (buff[buffer_index] && buffer_index < BUFF_SIZE && ! new_line)
	{
		*(line + line_index) = buff[buffer_index];
		line_index ++;
		buffer_index ++;
		if (buff[buffer_index - 1] == 10)
			new_line = 1;
	}
	ft_flush(buff, buffer_index);
	*end_of_line = line_index;
	return (new_line);
}

char	*ft_get_line(char *line, char buff[BUFF_SIZE], int fd, \
size_t *end_of_line)
{
	ssize_t	n_read;

	if (ft_fill_line(line, buff, end_of_line))
		return (ft_realloc(line, *end_of_line, *end_of_line));
	n_read = read(fd, buff, BUFF_SIZE);
	while (n_read > 0)
	{
		line = ft_realloc(line, *end_of_line + (size_t)n_read, *end_of_line);
		if (line == NULL)
			return (NULL);
		if (ft_fill_line(line, buff, end_of_line))
			return (ft_realloc(line, *end_of_line, *end_of_line));
		n_read = read(fd, buff, BUFF_SIZE);
	}
	if (n_read == -1 || ! *line)
	{
		free(line);
		return (NULL);
	}
	return (ft_realloc(line, *end_of_line, *end_of_line));
}
