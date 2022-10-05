/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:18:47 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/05 16:24:24 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

void	ft_putchar(char c);

int	ft_strlen(char *str)
{
	int	o;

	if (str == NULL)
		return (0);
	o = 0;
	while (*(str + o))
		o ++;
	return (o);
}

void	ft_putstr(char *str)
{
	if (str == NULL)
		return ;
	write(1, str, ft_strlen(str));
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		ft_putstr(av[i]);
		ft_putchar(10);
		i ++;
	}
	return (0);
}
