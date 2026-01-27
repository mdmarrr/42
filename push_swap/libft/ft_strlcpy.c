/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/19 18:13:23 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (src_len + 1 < size)
	{
		i = 0;
		while (i < src_len)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	else if (size != 0)
	{
		i = 0;
		while (i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

/*
#include <stdio.h>
int main(void)
{
	const char	*src;
	char		buffer1[20];
	char		buffer2[5];

	src = "Hello World";
	ft_strlcpy(buffer1, src, sizeof(buffer1));
	printf("%s\n", buffer1);
	ft_strlcpy(buffer2, src, sizeof(buffer2));
	printf("%s\n", buffer2);
	return (0);
}
*/