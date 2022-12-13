/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:29:53 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/09 08:26:52 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <strings.h>
#include <unistd.h>

int	main(void)
{
	char	buf[20] = "Bonjour";
	char	fbuf[20] = "Salut";
	char	*s;

	s = (char *)memset((void *)buf, 'q', 20);
	write(1, s, 20);
	write(1, "\n", 1);
	s = (char *)memset((void *)fbuf, 'a', 20);
	write(1, s, 20);
	return (0);
}
