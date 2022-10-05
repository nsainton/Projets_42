/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 01:00:32 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/06 01:19:52 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/display.h"
#include "../includes/strs.h"

void	ft_display(char *file)
{
	char	buff[4096];
	int		fd;
	int		nread;

	if (file == NULL)
		return ;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(2, "Error during file opening.\n");
		return ;
	}
	nread = read(fd, buff, 4096);
	while (nread > 0)
	{
		write(1, buff, nread);
		nread = read(fd, buff, 4096);
	}
	if (nread == -1)
	{
		ft_putstr(2, "Error during file reading.\n");
		return ;
	}
	if (close(fd) == -1)
		ft_putstr(2, "Error during file closing.\n");
}
