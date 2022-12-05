/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:09:56 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/05 02:45:02 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/debug.h"
#include "../includes/libftprintf.h"

void	print_flags(char flags[128])
{
	int	i;

	i = 0;
	while (*(FLAGS + i))
	{
		printf("La valeur de flags[%c] est : %d\n", *(FLAGS + i), \
		flags[(int)*(FLAGS + i)]);
		i ++;
	}
	printf("La valeur de flags[m] est : %d\n", flags[(int) 'm']);
}

void	print_buffer(t_pbuffer *buf)
{
	printf("buf->len : %d\n", buf->len);
	printf("buf->printed : %d\n", buf->printed);
	printf("buf->width : %d\n", buf->width);
	printf("buf->prec : %d\n", buf->prec);
	printf("buf->fd : %d\n", buf->fd);
}

void	print_tprint(t_print *p)
{
	printf("print->beg : %c\n", p->beg);
	printf("print -> align : %c\n", p->align);
	printf("print->pad : %c\n", p->pad);
}
