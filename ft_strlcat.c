/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2025/11/13 17:00:17 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	//if there is no space to concatenate
	if (dst_len >= size)
		return (size + src_len);
	//copy while there is space and before reaching the end of src
	i = 0;
	while (src[i] && (dst_len + i + 1) < size)
	{
		dst[dst_len + 1] = src[i];
		i++;
	}
	//add NULL terminator
	dst[dst_len + i] = '\0';
	//return the length of src + dest
	return (src_len + dst_len);
}
