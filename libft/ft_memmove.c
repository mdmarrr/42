/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/17 13:49:44 by magomez-         ###   ########.fr       */
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
int main(void)
{
    char buffer1[20] = "Hola mundo";
    char buffer2[20] = "Hola mundo";

    // Caso 1: sin solapamiento
    ft_memmove(buffer1 + 5, buffer1, 4); // copia "Hola" dentro de la misma cadena
    printf("ft_memmove sin solapamiento: %s\n", buffer1);

    // Caso 2: con solapamiento
    memmove(buffer2 + 5, buffer2, 4); // versión estándar para comparar
    printf("memmove   sin solapamiento: %s\n", buffer2);

    // Caso 3: copiar hacia atrás (solapamiento inverso)
    char buffer3[20] = "ABCDEFGHIJ";
    ft_memmove(buffer3, buffer3 + 2, 5); // mueve "CDEFG" al inicio
    printf("ft_memmove con solapamiento inverso: %s\n", buffer3);

    char buffer4[20] = "ABCDEFGHIJ";
    memmove(buffer4, buffer4 + 2, 5);
    printf("memmove   con solapamiento inverso: %s\n", buffer4);

    return 0;
}
*/