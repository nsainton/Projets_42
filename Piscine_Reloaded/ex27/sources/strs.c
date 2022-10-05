/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 00:51:49 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/06 00:56:13 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strs.h"

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (*(str + i))
		i ++;
	return (i);
}

void	ft_putstr(int fd, char *str)
{
	if (str == NULL)
		return ;
	write(fd, str, ft_strlen(str));
}
