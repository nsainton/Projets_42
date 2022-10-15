/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:03:27 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/15 20:08:15 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft_bonus.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (lst == NULL)
		return ;
	ptr = ft_lstlast(*lst);
	ptr->next = new;
}
