/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:36:43 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/16 09:50:14 by nsainton         ###   ########.fr       */
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

static void	*modify(void *s)
{
	char	*ns;
	char	*ptr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	ptr = (char *)s;
	i = ft_strlen(ptr);
	ns = (char *)malloc((i + 1) * sizeof(char));
	if (ns == NULL)
		return (NULL);
	i = 0;
	while (*(ptr + i))
	{
		*(ns + i) = ft_toupper(*(ptr + i));
		i ++;
	}
	*(ns + i) = 0;
	return ((void *)ns);
}

int	main(int ac, char **av)
{
	t_list	*lst;
	t_list	*newelem;
	t_list	*tmp;
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
	newelem = ft_lstmap(lst, modify, delete);
	ft_putstr_fd("Here is the size of the modified list : ", 1);
	i = ft_lstsize(newelem);
	ft_putnbr_fd(i, 1);
	ft_putchar_fd(10, 1);
	ft_putendl_fd("Here is the modified list :", 1);
	ft_lstiter(newelem, print);
	ft_putendl_fd("Here is the last element of the base list :", 1);
	ft_lstiter(ft_lstlast(lst), print);
	ft_putendl_fd("Deletion of the first element :", 1);
	tmp = lst->next;
	ft_lstdelone(lst, delete);
	lst = tmp;
	ft_putstr_fd("Here is the new size of the base list : ", 1);
	ft_putnbr_fd(ft_lstsize(lst), 1);
	ft_putchar_fd(10, 1);
	ft_putendl_fd("Here is the new base list :", 1);
	ft_lstiter(lst, print);
	ft_lstclear(&lst, delete);
	ft_lstclear(&newelem, delete);
	if (lst == NULL)
		ft_putendl_fd("Completed", 1);
	if (newelem == NULL)
		ft_putendl_fd("Modified list deleted", 1);
	return (0);
}
