/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/19 18:55:01 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == 0)
		return ((char *) big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && i + j < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *) big + i);
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	const char	*str;
	char		*res1;
	char		*res2;

	str = "Hello World welcomeeee";
	res1 = ft_strnstr(str, "World", 20);
	if (res1)
		printf("%s\n", res1);
	else
		printf("No encontrado\n");
	res2 = ft_strnstr(str, "42", 10);
	if (res2)
		printf("%s\n", res2);
	else
		printf("No encontrado\n");
	return (0);
}
*/