/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 01:14:13 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/06 01:17:10 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/display.h"
#include "includes/strs.h"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putstr(2, "File name missing.\n");
		return (1);
	}
	if (ac > 2)
	{
		ft_putstr(2, "Too many arguments.\n");
		return (2);
	}
	ft_display(av[1]);
	return (0);
}
