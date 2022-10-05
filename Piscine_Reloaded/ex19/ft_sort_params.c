/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:59:26 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/05 18:27:30 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

void	ft_putchar(char c);

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

void	ft_putstr(char *str)
{
	if (str == NULL)
		return ;
	write(1, str, ft_strlen(str));
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;
	char	stop;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	stop = 1;
	while (*(s1 + i) && *(s2 + i) && stop)
	{
		if (*(s1 + i) != *(s2 + i))
		{
			stop = 0;
			i --;
		}
		i ++;
	}
	return ((unsigned char)*(s1 + i) - \
	(unsigned char)*(s2 + i));
}

void	ft_sort_tab(char **tab, int size)
{
	char	*tmp;
	int		i;
	int		j;

	if (tab == NULL || size < 2)
		return ;
	j = size;
	while (j > 1)
	{
		i = 1;
		while (i < j)
		{
			if (ft_strcmp(*(tab + i - 1), *(tab + i)) > 0)
			{
				tmp = *(tab + i);
				*(tab + i) = *(tab + i - 1);
				*(tab + i - 1) = tmp;
			}
			i ++;
		}
		j --;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	ft_sort_tab(av + 1, ac - 1);
	while (i < ac)
	{
		ft_putstr(av[i]);
		ft_putchar(10);
		i ++;
	}
	return (0);
}
