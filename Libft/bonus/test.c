/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:36:43 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/15 20:55:00 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft_bonus.h"

static void	delete(void *s)
{
	char	*p;

	if (s == NULL)
		return ;
	p = (char *)s;
	*p = 0;
}

static void	print(void *s)
{
	char	*p;

	if (s == NULL)
		return ;
	p = (char *)s;
	ft_putendl_fd(p, 1);
}

int	main(int ac, char **av)
{
	t_list	*lst;
	t_list	*newelem;
	int		i;

	i = 1;
	lst = ft_lstnew((void *)*av);
	if (lst == NULL)
		return (1);
	while (i < ac)
	{
		newelem = ft_lstnew((void *)*(av + i));
		if (newelem == NULL)
		{
			ft_lstclear(&lst, delete);
			return (1);
		}
		ft_lstadd_back(&lst, newelem);
		i ++;
	}
	ft_lstiter(lst, print);
	ft_lstclear(&lst, delete);
	return (0);
}
