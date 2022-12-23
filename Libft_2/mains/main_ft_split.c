/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:36:36 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/14 13:57:35 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#include <time.h>

static void	ft_print_tab(char **tab)
{
	size_t	i;

	if (tab == NULL)
		return ;
	i = 0;
	while (*(tab + i))
	{
		printf("This : %s -- is the string number %ld of the table of strings\n",\
		*(tab + i), i);
		free(*(tab + i));
		i ++;
	}
	free(tab);
}

static void	ft_test(const char *s, char c)
{
	clock_t	start;
	double	cpu_time;
	char	**nt;

	start = clock();
	nt = ft_split(s, c);
	cpu_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	printf("This is the original string : %s -- and this is the separator : %c\n\n",\
	s, c);
	printf("This is the table returned by ft_split\n");
	ft_print_tab(nt);
	printf("It tooks %f seconds to compute\n\n\n", cpu_time);
}

int	main(void)
{
	ft_test("Bonjour", 'o');
	ft_test("Boonjour", 'o');
	ft_test("BBBBBB", 'B');
	ft_test("Bonjour", 'B');
	ft_test("Bonjour", 'r');
	ft_test("", 'r');
	ft_test("Bonjour", 'k');
	ft_test(NULL, 't');
	return (0);
}
