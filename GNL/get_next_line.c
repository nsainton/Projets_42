/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:22:22 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/17 14:11:41 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_next_line(int fd)
{
	static t_buffer	buff = {{0}, BUFF_SIZE, BUFF_SIZE};
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
	line = ft_realloc(line, ft_strlen(line));
	return (line);
}
