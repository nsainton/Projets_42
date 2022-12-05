/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 02:03:24 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/05 03:53:39 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 2)
		return (1);
	i = ft_printf("%i\n", ft_atoi(av[1]));
	j = printf("%i\n", ft_atoi(av[1]));
	printf("Retour de printf : %i\n", j);
	printf("Retour de ft_printf : %i\n", i);
	i = ft_printf("%.d\n", ft_atoi(av[1]));
	j = printf("%.d\n", ft_atoi(av[1]));
	printf("Retour de printf : %i\n", j);
	printf("Retour de ft_printf : %i\n", i);
	i = ft_printf("%+12.2d\n", ft_atoi(av[1]));
	j = printf("%+12.2d\n", ft_atoi(av[1]));
	printf("Retour de printf : %i\n", j);
	printf("Retour de ft_printf : %i\n", i);
	i = ft_printf("%+31.3d\n", ft_atoi(av[1]));
	j = printf("%+31.3d\n", ft_atoi(av[1]));
	printf("Retour de printf : %i\n", j);
	printf("Retour de ft_printf : %i\n", i);
	i = ft_printf("% 1.7d\n", ft_atoi(av[1]));
	j = printf("% 1.7d\n", ft_atoi(av[1]));
	printf("Retour de printf : %i\n", j);
	printf("Retour de ft_printf : %i\n", i);
	i = ft_printf("% -12.7d\n", ft_atoi(av[1]));
	j = printf("% -12.7d\n", ft_atoi(av[1]));
	printf("Retour de printf : %i\n", j);
	printf("Retour de ft_printf : %i\n", i);
	i = ft_printf("% -9.3d\n", ft_atoi(av[1]));
	j = printf("% -9.3d\n", ft_atoi(av[1]));
	printf("Retour de printf : %i\n", j);
	printf("Retour de ft_printf : %i\n", i);
	i = ft_printf("%.0d\n", ft_atoi(av[1]));
	j = printf("%.0d\n", ft_atoi(av[1]));
	printf("Retour de printf : %i\n", j);
	printf("Retour de ft_printf : %i\n", i);
	i = ft_printf("%0.d\n", ft_atoi(av[1]));
	j = printf("%0.d\n", ft_atoi(av[1]));
	printf("Retour de printf : %i\n", j);
	printf("Retour de ft_printf : %i\n", i);

	return (0);
}
