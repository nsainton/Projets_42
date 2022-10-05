/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:53:12 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/06 00:07:57 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	count;

	if (tab == NULL || f == NULL)
		return (0);
	i = 0;
	while (*(tab + i))
	{
		if (f(*(tab + i)) == 1)
			count ++;
		i ++;
	}
	return (count);
}

//TEST
#include <stdio.h>

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

int	main(int ac, char **av)
{
	(void)ac;
	printf("%d\n", ft_count_if(av, &ft_strlen));
	return (0);
}
