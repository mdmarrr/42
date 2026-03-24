/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/19 17:24:09 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}

/*
#include <stdio.h>
int main(void)
{
	const char	*str;
	char		*c;
	char		*c2;

	str = "Hello World";
	c = ft_strchr(str, 'o');
	if (c)
		printf("%s\n", c);
	else
		printf("No se encontró 'o'\n");
	c2 = ft_strchr(str, 'z');
	if (c2)
		printf("%s\n", c2);
	else
		printf("No se encontró 'z'\n");
}
*/