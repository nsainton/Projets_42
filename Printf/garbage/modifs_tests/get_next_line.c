/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:06:27 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/15 23:52:47 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[FILES][BUFFER_SIZE] = {{0}, {0}};
	char		*line;
	size_t		line_length;

	if (fd < 0 || fd > FILES - 1)
		return (NULL);
	if (BUFFER_SIZE < 1 || BUFFER_SIZE > SIZE_MAX)
		return (NULL);
	line = malloc(sizeof * line * BUFFER_SIZE);
	if (line == NULL)
		return (NULL);
	line_length = 0;
	*line = 0;
	line = ft_get_line(line, buff[fd], fd, &line_length);
	if (line != NULL && ! *line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
