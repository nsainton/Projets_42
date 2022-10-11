/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:23:15 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/11 18:32:19 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>
#include <stdio.h>

static void	ft_search(const char *str, int c)
{
	printf("Voici la chaîne originale : %s et voici le charactère cherché : %c\n",\
	str, c);
	printf("strchr : %s -- ft_strchr : %s\n", strchr(str, c), ft_strchr(str, c));
	printf("strrchr : %s -- ft_strrchr : %s\n", strrchr(str, c), ft_strrchr(str, c));
}

int	main(void)
{
	ft_search("Bonjour", 'B');
	ft_search("Bonjour", 'o');
	ft_search("Bonjour", 'r');
	ft_search("Bonjour", 0);
	ft_search("Bonjour", 'c');
	return (0);
}
