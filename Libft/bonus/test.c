/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:36:43 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/16 09:22:15 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_bonus.h"

static void	message(char *s, char c);

static void delete(void *s)
{
	if (s == NULL)
		return ;
	message(s, 45);
	free(s);
}
	
static void	print(void *s)
{
	char	*p;

	if (s == NULL)
		return ;
	p = (char *)s;
	ft_putstr_fd("This is the string : ", 1);
	ft_putendl_fd(p, 1);
}

static void	message(char *s, char c)
{
	if (s == NULL)
		return ;
	if (c == 43)
		ft_putstr_fd("New string : ", 1);
	else if (c == 45)
		ft_putstr_fd("String : ", 1);
	ft_putstr_fd(s, 1);
	if (c == 43)
		ft_putendl_fd(" created", 1);
	else if (c == 45)
		ft_putendl_fd(" deleted", 1);
}

static t_list	*ft_create(char *s)
{
	char 	*ns;
	t_list	*ne;

	ns = ft_strdup(s);
	if (ns == NULL)
		return (NULL);
	message(s, 43);
	ne = ft_lstnew((void *)ns);
	if (ne == NULL)
		free(ns);
	return (ne);
}

int	main(int ac, char **av)
{
	t_list	*lst;
	t_list	*newelem;
	int		i;

	i = 1;
	lst = ft_create(*av);
	if (lst == NULL)
		return (1);
	while (i < ac)
	{
		newelem = ft_create(*(av + i));
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
		newelem = ft_create(*(av + i));
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
