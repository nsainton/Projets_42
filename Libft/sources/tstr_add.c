/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstr_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 04:34:33 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/27 04:47:02 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	tstr_addchar(t_str *str, char c)
{
	if (str->len >= str->size)
		return (1);
	*(str->str + str->len) = c;
	str->len += 1;
	return (0);
}

int	tstr_addstr(t_str *str, const t_str *toadd)
{
	if (str->len + toadd->len >= str->size)
		return (str->len + toadd->len - str->size + 1);
	ft_strlcat(str->str, toadd->str, str->size);
	str->len += toadd->len;
	return (0);
}
