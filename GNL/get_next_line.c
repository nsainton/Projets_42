/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:06:27 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/10 15:27:03 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_next_line(int fd)
{
	static char	buff[FILES][BUFF_SIZE] = {{0}, {0}};
	char		*line;
	size_t		line_length;

	if (fd < 0 || fd > FILES - 1)
		return (NULL);
	if (BUFF_SIZE < 1 || BUFF_SIZE > SIZE_MAX)
		return (NULL);
	line = (char *)malloc(BUFF_SIZE * sizeof(char));
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
