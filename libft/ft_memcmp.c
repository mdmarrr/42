/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/19 18:44:46 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char) str1[i] != (unsigned char) str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int main(void)
{
    char a[] = "Hola";
    char b[] = "Holanda";
    char c[] = "Hola";

    printf("%d\n", ft_memcmp(a, b, 4));
    printf("%d\n", ft_memcmp(a, b, 5));
    printf("%d\n", ft_memcmp(a, c, 4));
    return 0;
}
*/