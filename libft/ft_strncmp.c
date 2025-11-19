/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/19 18:45:23 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_strncmp("Hola", "Hola", 4));
	printf("%d\n", ft_strncmp("Hola", "Holanda", 7));
	printf("%d\n", ft_strncmp("Hola", "Holaaa", 4));
	printf("%d\n", ft_strncmp("Holaaa", "Hola", 6));
	return (0);
}
*/