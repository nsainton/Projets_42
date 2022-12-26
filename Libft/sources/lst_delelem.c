/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delelem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:12:24 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/26 22:15:44 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del) (void *))
{
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*p;
	t_list	*q;

	p = *lst;
	while (p->next != NULL)
	{
		q = p->next;
		del(p->content);
		free(p);
		p = q;
	}
	del(p->content);
	free(p);
	*lst = NULL;
}
