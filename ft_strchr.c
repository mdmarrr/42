/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/13 15:17:20 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	/*convert int c to char*/
	cc = (char) c;
	i = 0;
	/*if we find c in the string we return the address of the char as a char pointer*/
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	/*if the caracter to find is '\0' we have to check again 
    after checking the string and return the address of '\0' as a char pointer*/
	if (s[i] == cc)
		return ((char *) &s[i]);
	/*reaching this point means there is no occurrence of c in the string so we return NULL*/
	return (NULL);
}
