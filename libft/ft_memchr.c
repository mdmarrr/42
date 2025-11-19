/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/17 13:28:12 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	uc;
	size_t			i;

	str = (unsigned char *) s;
	uc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == uc)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int main(void)
{
    char buffer[] = "Hola mundo";
    char c = 'm';
    char *result;

    // buscar 'm' en los primeros 10 caracteres
    result = ft_memchr(buffer, c, 10);
    if (result)
        printf("Carácter '%c' en la posición %ld\n", c, result - buffer);
    else
        printf("Carácter '%c' no encontrado\n", c);

    // buscar 'z' en los primeros 10 caracteres
    c = 'z';
    result = ft_memchr(buffer, c, 10);
    if (result)
        printf("Carácter '%c' en la posición %ld\n", c, result - buffer);
    else
        printf("Carácter '%c' no encontrado\n", c);
    return 0;
}
*/