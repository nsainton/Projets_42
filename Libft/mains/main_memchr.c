/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:42:52 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/12 14:52:23 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#include <string.h>

static void	ft_comp_func(const void *s, int c, size_t n)
{
	printf("Voici la chaîne de départ : %s -- Et le charactère recherché : %c\n",\
	(char *)s, (unsigned char)c);
	printf("Retour de memchr : %s -- Et retour de ft_memchr : %s\n",\
	(char *)memchr(s, c, n), (char *)ft_memchr(s, c, n));
}

int	main(void)
{
	char	s[20] = "Bonjour";

	ft_comp_func((void *)s, 'B', 20);
	ft_comp_func((void *)s, 'o', 20);
	ft_comp_func((void *)s, 0, 20);
	ft_comp_func((void *)s, 'k', 100);
}
