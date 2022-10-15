/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:15:47 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/15 19:39:59 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H
# include "libft.h"

int		ft_lstsize(t_list *lst);

t_list	*ft_lstnew(void *content);

t_list	*ft_lstadd_front(t_list **lst, t_list *new);
#endif
