/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:26:14 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/18 19:28:38 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <sys/stat.h>
#include <fcntl.h>

void	modify(const char *s, const char *t, int fd)
{
	while (*s && s != t)
	{
		ft_putchar_fd(*s, fd);
		s ++;
	}
	ft_putstr_fd("ft_printf", fd);
	s += ft_strlen("printf");
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s ++;
	}
}

void	write_line(int from, int to)
{
	char	*line;
	char	*tmp;

	line = get_next_line(from);
	while (line != NULL)
	{
		tmp = ft_strnstr(line, "printf", ft_strlen(line));
		if (tmp != NULL)
			modify(line, tmp, to);
		else
			ft_putstr_fd(line, to);
		free(line);
		line = get_next_line(from);
	}
}

int	main(void)
{
	int		printF;
	int		ft_printF;

	printF = open("../test_printf.c", O_RDONLY);
	ft_printF = open("../test_ftprintf.c", O_CREAT | O_WRONLY);
	if (printF == -1 || ft_printF == -1)
	{
		ft_putstr_fd("Opening error\n", 1);
		return (1);
	}
	write_line(printF, ft_printF);
	close(printF);
	close(ft_printF);
	return (0);
}
