/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:26:57 by nsainton          #+#    #+#             */
/*   Updated: 2022/12/19 16:15:21 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

struct gap{
	char	c;
	int		s;
};

struct	no_gap{
	int		s;
	char	c;
};

int	main(void)
{
	printf("sizeof (struct gap) : %ld\n", sizeof(struct gap));
	printf("sizeof (struct no_gap) : %ld\n", sizeof(struct no_gap));
	return (0);
}
