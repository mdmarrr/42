/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chech_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/01/27 11:06:50 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_error(char **argv, int i, int j)
{
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j] != '\0'))
		{
			if (sign(argv[i][j]))
			{
				j++;
				if (!digit(argv[i][j]))
					return (false);
			}
			else if (digit(argv[i][j]))
			{
				j++;
				if (argv[i][j] == '\0')
					break ;
				if (!digit(argv[i][j]))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
