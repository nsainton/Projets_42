/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:28:52 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/15 20:30:48 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft_bonus.h"

void	ft_lstiter(t_list *lst, void (*f) (void *))
{
	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst);
		lst = lst->next;
	}
}
