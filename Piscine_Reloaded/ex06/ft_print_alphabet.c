/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:52:42 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/05 13:03:23 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char	alphabet[26];
	char	letter;

	letter = 97;
	while (letter < 123)
	{
		alphabet[letter - 97] = letter;
		letter ++;
	}
	alphabet[26] = 10;
	write(1, alphabet, 27);
}

int	main(void)
{
	ft_print_alphabet();
	return (0);
}
