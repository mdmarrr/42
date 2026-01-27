/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/14 13:06:05 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	while (i < nmemb * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}

/*
#include <stdio.h>
int main(void)
{
	int 	*arr;
	size_t	i;
    size_t 	n;

	n = 5;
    arr = (int *)ft_calloc(n, sizeof(int));
    if (!arr)
    {
        printf("Error\n");
        return 1;
    }
	i = 0;
    while (i < n)
        printf("arr[%zu] = %d\n", i, arr[i++]);
    free(arr);
    return 0;
}
*/