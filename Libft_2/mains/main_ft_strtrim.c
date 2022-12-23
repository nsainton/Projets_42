/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:46:03 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/13 14:12:08 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#include <time.h>

static void	ft_test(const char *s1, const char *set)
{
	clock_t	start;
	double	cpu;
	char	*ns;

	start = clock();
	ns = ft_strtrim(s1, set);
	cpu = (double)(clock() - start) / CLOCKS_PER_SEC;
	printf("This is the string to trim : %s -- And this is the set : %s\n\n",\
	s1, set);
	printf("ft_strtrim returned the following string : %s\n", ns);
	printf("The function took %f seconds to return the result\n\n\n", cpu);
	if (ns)
		free(ns);
}

int	main(void)
{
	ft_test("       BONJOUR   !!!!!    j        ", " ");
	ft_test("tttttttBonjourttttttt", "t");
	ft_test("BONJOUR_____", "_");
	ft_test("bonjour comnment ca va ??  ads", "bonjour??");
	ft_test("+++++Bonjoru", "+");
	ft_test("++++Bonjoru", "++K");
	ft_test("Bonjour", "");
	ft_test("BONJOUR", NULL);
	ft_test(NULL, "string");
	ft_test(NULL, NULL);
	return (0);
}
