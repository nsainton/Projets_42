/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:52:27 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/19 23:05:47 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_next_line(int fd)
{
	static char	buff[FILES][BUFF_SIZE] = {{0}, {0}};
	char		*line;
	size_t		line_index;

	if (fd > FILES - 1)
		return (NULL);
	line = (char *)malloc(sizeof(char));
	if (line == NULL)
		return (NULL);
	line_index = 0;
	*line = 0;
	return (ft_get_line(line, (char **)buff, fd, &line_index));
}
