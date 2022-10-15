/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:36:43 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/15 22:08:23 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_bonus.h"

static void	delete(void *s)
{
	char	*p;

	if (s == NULL)
		return ;
	p = (char *)s;
	*p = 0;
}

static void del(void *s)
{
	
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
	char	*ns;
	int		i;

	i = 1;
	ns = ft_strdup(*av);
	if (ns == NULL)
		return (1);
	lst = ft_lstnew((void *)*av);
	if (lst == NULL)
		return (1);
	while (i < ac)
	{
		ns = ft_strdup(*(av + i));
		newelem = ft_lstnew((void *)ns);
		if (newelem == NULL)
		{
			ft_lstclear(&lst, delete);
			return (1);
		}
		//ft_putendl_fd((char *)newelem->content, 1);
		ft_lstadd_front(&lst, newelem);
		i ++;
	}
	i = 1;
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
	if (lst == NULL)
		ft_putendl_fd("Completed", 1);
	return (0);
}
