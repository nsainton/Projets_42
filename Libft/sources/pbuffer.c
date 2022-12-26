/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbuffer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:43:06 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/26 21:05:12 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	add_char(t_pbuffer *buf, char c)
{
	if (buf->len > PBUFFER_SIZE - 2)
		flush(buf);
	if (buf->printed == -1)
		return ;
	(buf->buffer)[buf->len] = c;
	buf->len += 1;
}

void	add_nchar(t_pbuffer *buf, char c, int n)
{
	while (n > 0)
	{
		add_char(buf, c);
		if (n % 100 == 0 && buf->printed == -1)
			return ;
		n --;
	}
}

void	add_str(t_pbuffer *buf, char *str)
{
	if (str == NULL)
		return ;
	while (*str)
	{
		add_char(buf, *str);
		str ++;
	}
}

void	add_nstr(t_pbuffer *buf, char *str, int n)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (i < n && *(str + i))
	{
		add_char(buf, *(str + i));
		i ++;
	}
}
