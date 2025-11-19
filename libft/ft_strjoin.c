/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/19 17:54:29 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		res[j] = s2[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

/*
#include <stdio.h>
int	main(void)
{
	const char	*s1;
	const char	*s2;
	char		*res;

	s1 = "Hola ";
	s2 = "Mundo";
	res = ft_strjoin(s1, s2);
	if (res == NULL)
	{
		printf("Error al reservar memoria");
		return (1);
	}
	printf("Cadena 1: %s\n", s1);
	printf("Cadena 2: %s\n", s2);
	printf("Resultado: %s\n", res);
	free(res);
	return (0);
}
*/