/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 05:32:13 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/13 08:07:30 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libftprintf.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac < 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_printf("%s", line);
		ft_strncmp(line, "0123456789012345678901234567890123456789012", 89);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
