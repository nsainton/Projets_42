/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:42:04 by nsainton          #+#    #+#             */
/*   Updated: 2022/11/17 00:25:26 by nsainton         ###   ########.fr       */
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

	i = printf("Bonjour\n");
	printf("Retour de la fonction : %d\n", i);
	i = printf("Bonjour%d\n", i);
	printf("Retour de la fonction : %d\n", i);
	i = printf("Un nombre en hexa%x\n", 129);
	printf("Retour de la fonction : %d\n", i);
	i = printf("Le meme en maj : %X\n", 129);
	printf("Retour de la fonction : %d\n", i);
	i = printf("Plusieurs %c arguments %d histoire %x de %X tester %s\n",\
	'c', 123, 123, 123, "Bonjour");
	printf("Retour de la fonction : %d\n", i);
	i = printf("Avec un pointeur : %p\n", &i);
	printf("Retour de la fonction : %d\n", i);
	i = printf("Et un pointeur invalide : %p\n", NULL);
	printf("Retour de la fonction : %d\n", i);
	i = printf("Voici ce que donne l'affichage avec une chaine nulle : %s\n",\
	s);
	printf("Retour de la fonction : %d\n", i);
	i = printf("Et avec une chaine vide : %s\n", "");
	printf("Retour de la fonction : %d\n", i);
	i = printf("Un hexa non null avec un flag : %#x\n", 123);
	printf("Retour de la fonction : %d\n", i);
	i = printf("Un hexa negatif avec un flag : %#X\n", -123);
	printf("Retour de la fonction : %d\n", i);
	i = printf("Zero en hexa avec un flag : %#X\n", 0);
	printf("Retour de la fonction : %d\n", i);
	i = printf("Un hexa positif avec un flag : %#x\n", 12);
	printf("Retour de la fonction : %d\n", i);
	i = printf("Un entier positif : %+d\n", 123);
	printf("Retour de la fonction : %d\n", i);
	i = printf("Un autre entier positif : % d\n", 123);
	printf("Retour de la fonction : %d\n", i);
}
