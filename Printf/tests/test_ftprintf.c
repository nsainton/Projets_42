/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ftprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:42:04 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/18 01:32:53 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

static void	test(void);

int	main(void)
{
	test();
	return (0);
}

static void test(void)
{
	int		i;
	char	*s = NULL;

	i = ft_printf("Bonjour\n");
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("Bonjour : %d\n", i);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("Un nombre en hexa : %x\n", 129);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("Le meme en maj : %X\n", 129);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("Plusieurs | %c | arguments |%d| histoire |%x| de |%X| tester |%s|\n",\
	'c', 123, 123, 123, "Bonjour");
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("Avec un pointeur : %p\n", &i);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("Et un pointeur invalide : %p\n", NULL);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("Voici ce que donne l'affichage avec une chaine nulle : %s\n",\
	s);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("Et avec une chaine vide : %s\n", "");
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("Un hexa negatif : %x\n", -1);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("Un entier negatif : %d\n", -456);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("Un unsigned int random : %u\n", 1239);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("Et un integer (en vrai c'est la meme) : %i\n", 230);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("Un hexa non null avec un flag : %#x\n", 123);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("Un hexa negatif avec un flag : %#X\n", -123);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("Zero en hexa avec un flag : %#X\n", 0);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("Un hexa positif avec un flag : %#x\n", 12);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("Un entier positif : %+d\n", 123);
	ft_printf("Retour de la fonction : %d\n", i);
	i = ft_printf("Un autre entier positif : % d\n", 123);
	ft_printf("Retour de la fonction : %d\n", i);
}
