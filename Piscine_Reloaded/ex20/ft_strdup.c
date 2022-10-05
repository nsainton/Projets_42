/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:37:06 by nsainton          #+#    #+#             */
/*   Updated: 2022/10/05 19:00:21 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (*(str + i))
		i ++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*ns;

	len = ft_strlen(src);
	if (len < 0)
		return (NULL);
	ns = (char *)malloc((len + 1) * sizeof(char));
	if (ns == NULL)
		return (NULL);
	len = 0;
	while (*(src + len))
	{
		*(ns + len) = *(src + len);
		len ++;
	}
	*(ns + len) = 0;
	return (ns);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	int		i;
	char	*ns;

	i = 0;
	while (i < ac)
	{
		ns = ft_strdup(av[i]);
		if (ns != NULL)
		{
			printf("Voici la chaîne : %s | et la chaîne dupliquée %s \n", \
			av[i], ns);
			free(ns);
		}
		i ++;
	}
	return (0);
}
