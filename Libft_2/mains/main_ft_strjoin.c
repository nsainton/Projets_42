/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:02:35 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/13 13:09:44 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#include <time.h>

static void	ft_test(const char *s1, const char *s2)
{
	clock_t	start;
	double	cpu_time;
	char	*ns;

	start = clock();
	ns = ft_strjoin(s1, s2);
	cpu_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	printf("Voici la première chaîne : %s -- et voici la deuxième : %s\n\n",\
	s1, s2);
	printf("Voici le retour de la fonction ft_strjoin : %s\n", ns);
	printf("Ce retour s'est effectué en %f secondes\n\n\n", cpu_time);
	if (ns != NULL)
		free(ns);
}

int	main(void)
{
	ft_test("Bonjour", " les amis");
	ft_test("Bien le bonjour", "");
	ft_test("Salut", "");
	ft_test("Bienvenue dans le test", NULL);
	ft_test(NULL, "Encore un peu");
	ft_test(NULL, NULL);
	return (0);
}
