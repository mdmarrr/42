/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/13 13:34:46 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
    c = 'a';
    printf("%d\n", ft_isascii(c));
    printf("%d\n", isascii(c));
    c = 128;
    printf("%d\n", ft_isascii(c));
    printf("%d\n", isascii(c));
}
*/