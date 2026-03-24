/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/19 16:40:02 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp_str;

	temp_str = (unsigned char *)s;
	while (n > 0)
	{
		*(temp_str) = (unsigned char)c;
		temp_str++;
		n--;
	}
	return (s);
}

/*
#include <stdio.h>
int main(void)
{
	char	*string;
	char	buffer[20];

	memset(buffer, 0, sizeof(buffer));
	string = (char *) memset(buffer, 'A', 10);
	printf("%s\n", string);

	ft_memset(buffer, 0, sizeof(buffer));
	string = (char *) ft_memset(buffer, 'A', 10);
	printf("%s\n", string);
}
*/