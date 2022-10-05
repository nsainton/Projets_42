/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:57:52 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/05 12:59:45 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char	letter;

	letter = 97;
	while (letter < 123)
	{
		ft_putchar(letter);
		letter ++;
	}
	ft_putchar(10);
}

int	main(void)
{
	ft_print_alphabet();
	return (0);
}
