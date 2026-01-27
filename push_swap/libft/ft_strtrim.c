/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/19 19:05:30 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trimmed = (char *)malloc(end - start + 1);
	if (!trimmed)
		return (NULL);
	ft_strlcpy (trimmed, s1 + start, end - start + 1);
	return (trimmed);
}

/*
#include <stdio.h>
int main(void)
{
	const char	*texto1 = "   Hello World   ";
	const char	*texto2 = "---42---";
	char *res1;
	char *res2;

	res1 = ft_strtrim(texto1, " ");
	printf("%s\n", res1);
	free(res1);
	res2 = ft_strtrim(texto2, "-");
	printf("%s\n", res2);
	free(res2);
	return (0);
}
*/