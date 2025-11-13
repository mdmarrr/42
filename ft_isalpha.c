/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/13 15:00:43 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int main(void)
{
    char c;
    c = 'd';
    printf("%d\n", ft_isalpha(c));
    printf("%d\n", isalpha(c));
}
*/