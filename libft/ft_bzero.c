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
#include <strings.h>
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