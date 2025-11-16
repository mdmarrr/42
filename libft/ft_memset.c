/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/13 15:12:45 by magomez-         ###   ########.fr       */
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
#define BUF_SIZE 20
int main(void)
{
	char *string;
	char buffer[BUF_SIZE + 1];

	memset(buffer, 0, sizeof(buffer));
	string = (char *) memset(buffer, 'A', 10);
	printf("%s\n", string);

	ft_memset(buffer, 0, sizeof(buffer));
	string = (char *) ft_memset(buffer, 'A', 10);
	printf("%s\n", string);
}
*/