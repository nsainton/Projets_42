/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:49:26 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/07 14:33:42 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

void	ft_open_error(char *str)
{
	if (str == NULL)
		return ;
	printf("Error while opening %s\n", str);
}

int	ft_error(char *str, void (*err) (char *))
{
	if (str != NULL)
		err(str);
	return (1);
}

void	ft_modif(int file, int nfile)
{
	char	*str;
	int		i;
	static char	tmp[40] = "#include \"includes/libft.h\"\n";

	i = 1;
	str = ft_get_next_line(file);
	while (str != NULL)
	{
		if (i == 13)
			write(nfile, tmp, strlen(tmp));
		else
			write(nfile, str, strlen(str));
		i ++;
		free(str);
		str = ft_get_next_line(file);
	}
}

int	main(int ac, char **av)
{
	int	file;
	int	nfile;
	char	cp[100];

	(void)ac;
	file = open(*(av + 1), O_RDONLY);
	if (file == -1)
		return (ft_error(*(av + 1), ft_open_error));
	*cp = 0;
	strcat(cp, *(av + 1));
	*(cp + strlen(*(av + 1)) - 2) = 0;
	strcat(cp, "_cp.c");
	nfile = open(cp, O_CREAT | O_WRONLY);
	if (nfile == -1)
		return (close(file), ft_error(cp, ft_open_error));
	ft_modif(file, nfile);
	close(file);
	close(nfile);
	return (0);
}
