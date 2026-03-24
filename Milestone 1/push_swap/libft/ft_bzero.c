/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/17 13:28:41 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp_str;

	temp_str = (unsigned char *)s;
	while (n > 0)
	{
		*(temp_str) = 0;
		temp_str++;
		n--;
	}
}

/*
#include <stdio.h>
int main(void)
{
    int i;
    char buffer[10] = "abcdef";
    printf("Array inicial: \"%s\"\n", buffer);
    // poner a cero los primeros 3 bytes
    ft_bzero(buffer, 3);
    printf("String al aplicar bzero: \"%s\"\n", buffer);
    printf("Hex al aplicar bzero: ");
    i = 0;
    while (i < 6)
        printf("%02x ", (unsigned char)buffer[i++]);
    printf("\n");
    return 0;
}
*/