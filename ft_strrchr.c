/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/13 14:46:12 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;
	char			*res;

	/*convert int c to char*/
	cc = (char) c;
	/*if we don't find c the function returns NULL*/
	res = NULL;
	i = 0;
	/*if we find c in the string we set res as the address of the char (as a char pointer)*/
	while (s[i])
	{
		if (s[i] == cc)
			res = (char *) &s[i];
		i++;
	}
	/*if the caracter to find is '\0' we have to check again after 
	checking the string and set res as the address of '\0' (as a char pointer)*/
	if (s[i] == cc)
		res = (char *) &s[i];
	/*at the end of the function we return res, if there is no occurrence of c
	the function returns NULL since res was set to NULL at the beggining*/
	return (res);
}
