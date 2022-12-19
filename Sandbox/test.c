/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:12:23 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/19 12:24:56 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>

typedef int (*t_func)(const char *, ...);

typedef struct	s_test
{
	char	c;
	char	d;
	char	e;
}				t_test;

struct s_void{char c;};
typedef struct	s_atest
{
	_Alignas(int) char	c;
	_Alignas(int) char	d;
	char				e;
}				t_atest;
int	main(void)
{
	char s<:10:> = "Bonjour\n";
	short unsigned	t;
	ptrdiff_t	ret;
	t_func		test;

	s<:0:> = 0;
	ret = (void *)printf - (void *)write;
	test = (void *)write - 756748;
	t = 0;
	printf("%c\n", '\a');
	printf("%u\n", t);
	printf("%d\n", _Alignof(t_test));
	printf("%d\n", sizeof(struct s_void));
	printf("%d\n", sizeof(t_atest));
	printf("%d\n", _Alignof(t_atest));
	//++ t++; impossible, raises an error
	printf("Voici la valeur de t : %d\n", t);
	printf("Voici la fonction : %s\n", __func__);
	printf("Voici l'addresse de write : %p\n", write);
	printf("Voici l'addresse de test : %p\n", test);
	printf("Voici la difference entre printf et write : %ld\n", ret);
	test("Voici la fonction printf utilisee dans une variable test\n");
	return (0);
}
