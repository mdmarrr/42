/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/17 10:10:49 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= 48 && c <= 57))
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
    c = '&';
    printf("%d\n", ft_isalnum(c));
    printf("%d\n", isalnum(c));
	c = 'a';
    printf("%d\n", ft_isalnum(c));
    printf("%d\n", isalnum(c));
	c = '7';
    printf("%d\n", ft_isalnum(c));
    printf("%d\n", isalnum(c));
}
*/