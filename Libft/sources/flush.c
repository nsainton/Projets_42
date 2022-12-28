/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:38:01 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/28 18:35:23 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	flush(t_pbuffer *buf)
{
	if (buf->str)
		flush_str(buf);
	else
		flush_fd(buf);
}

void	flush_fd(t_pbuffer *buf)
{
	int	printed;

	if (buf->printed == -1)
		return ;
	printed = (int)write(buf->fd, buf->buffer, buf->len);
	if (printed < 0)
		buf->printed = -1;
	else
		buf->printed += printed;
	buf->len = 0;
}

void	flush_str(t_pbuffer *buf)
{
	int		printed;
	t_str	*str;
	size_t	to_print;

	str = (t_str *)buf->fd;
	write(2, "Bonjour\n", 8);
	if (buf->printed == -1)
		return ;
	if (buf->len + str->len >= str->size - 1)
		to_print = str->size - str->len - (str->size > str->len);
	else
		to_print = buf->len;
	if (! to_print)
	{
		if (!buf->printed)
			buf->printed = -1;
		return ;
	}
	printed = (int)ft_strncat(str->str, buf->buffer, to_print);
	buf->printed += printed;
	str->len += printed;
	buf->len = 0;
}
