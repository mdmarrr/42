/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/20 09:44:23 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

/*
#include <stdio.h>
int main(void)
{
	char	*s;
	char	*cadena1;
	char	*cadena2;
	char	*cadena3;

	s = "Hello world";
	cadena1 = ft_substr(s, 0, 7);
	cadena2 = ft_substr(s, 20, 5);
	cadena3 = ft_substr(s, 3, 50);
	printf("cadena1: '%s'\n", cadena1);
	printf("cadena2: '%s'\n", cadena2);
	printf("cadena3: '%s'\n", cadena3);
	free(cadena1);
	free(cadena2);
	free(cadena3);
	return (0);
}
*/