/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:18:15 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/16 09:25:16 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*p;
	t_list	*q;

	if (lst == NULL)
		return ;
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
