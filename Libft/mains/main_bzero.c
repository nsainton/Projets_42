/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 08:36:37 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/11 14:34:11 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <strings.h>
#include <stdio.h>
#include <unistd.h>

static void	ft_print_memory(void *memzone, size_t size)
{
	char	*ns;
	size_t	i;

	if (memzone == NULL)
		return ;
	i = 0;
	ns = (char *)memzone;
	while (i < size)
	{
		if (*(ns + i) == 0)
			write(1, "0", 1);
		else
			write(1, ns + i, 1);
		write(1," ", 1);
		i ++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	int	i;
	int	l;

	i = 0;
	while (i < ac)
	{
		l = ft_strlen(av[i]);
		if (l > 3)
		{
			bzero((void *)(*(av + i) + 3), 1);
			ft_print_memory((void *)*(av + i), l);
			ft_bzero((void *)(*(av + i) + 1), 1);
			ft_print_memory((void *)*(av + i), l);
		}
		i ++;
	}
	return (0);
}
