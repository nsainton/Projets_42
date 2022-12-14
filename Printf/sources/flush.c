/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:38:01 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/14 10:12:39 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	flush(t_pbuffer *buf)
{
	if (buf->str)
		return ;
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
