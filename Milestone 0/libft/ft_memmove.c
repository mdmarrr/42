/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/19 16:36:32 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	size_t			count;

	if (!dest && !src)
		return (NULL);
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	count = 0;
	if (temp_dest > temp_src)
	{
		while (n-- > 0)
			temp_dest[n] = temp_src[n];
	}
	else
	{
		while (count < n)
		{
			temp_dest[count] = temp_src[count];
			count++;
		}
	}
	return (dest);
}

/*
#include <stdio.h>
int	main(void)
{
	char buffer1[20] = "Hola world";
	char buffer2[20] = "Hola world";
	char buffer3[20] = "Hola world";
	char buffer4[20] = "Hola world";

	ft_memmove(buffer1 + 5, buffer1, 4);
	printf("Sin solapamiento: %s\n", buffer1);
	memmove(buffer2 + 5, buffer2, 4);
	printf("Sin solapamiento: %s\n", buffer2);
	ft_memmove(buffer3, buffer3 + 2, 5);
	printf("Con solapamiento inverso: %s\n", buffer3);
	memmove(buffer4, buffer4 + 2, 5);
	printf("Con solapamiento inverso: %s\n", buffer4);
	return (0);
}
*/