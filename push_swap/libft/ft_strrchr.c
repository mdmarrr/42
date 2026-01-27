/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/19 19:00:13 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;
	char			*res;

	cc = (char) c;
	res = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			res = (char *) &s[i];
		i++;
	}
	if (s[i] == cc)
		res = (char *) &s[i];
	return (res);
}

/*
#include <stdio.h>
int	main(void)
{
	const char	*str;
	char		*res1;
	char		*res2;

	str = "Hello World";
	res1 = ft_strrchr(str, 'o');
	if (res1)
		printf("%s\n", res1);
	else
		printf("No encontrado");
	res2 = ft_strrchr(str, 'a');
	if (res2)
		printf("%s\n", res2);
	else
		printf("No encontrado");
	return (0);
}
*/