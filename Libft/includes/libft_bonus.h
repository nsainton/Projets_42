/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:15:47 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/15 20:26:18 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H
# include "libft.h"

int		ft_lstsize(t_list *lst);

void	ft_lstadd_front(t_list **lst, t_list *new);

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del) (void *));

void	ft_lstclear(t_list *lst, void (*del) (void *));

t_list	*ft_lstnew(void *content);

t_list	*ft_lstlast(t_list *lst);
#endif
