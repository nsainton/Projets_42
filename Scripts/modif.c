/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 02:21:26 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/27 03:25:05 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/libft.h"
#include <sys/stat.h>
#include <fcntl.h>
#define TMP "/tmp/tmpfile"
void	modif(char *line, int fd)
{
	static const char	LINE[100] = "#include \"libft.h\"";
	static const char	MODIF[100] = "#include \"../../includes/libft.h\"\n";

	if (ft_strnstr(line, LINE, ft_strlen(LINE)))
		write(fd, MODIF, ft_strlen(MODIF));
	else
		write(fd, line, ft_strlen(line));
}

int	main(int ac, char **av)
{
	int		fd1;
	int		fd2;
	char	*line;

	if (ac != 3)
		return (0);
	fd1 = open(av[1], O_RDONLY);
	if (fd1 < 0)
		return (1);
	fd2 = open(av[2], O_CREAT | O_WRONLY);
	if (fd2 < 0)
		return (close(fd2), 2);
	line = get_next_line(fd1);
	while (line != NULL)
	{
		modif(line, fd2);
		free(line);
		line = get_next_line(fd1);
	}
	close(fd1), close(fd2);
	return (0);
}
