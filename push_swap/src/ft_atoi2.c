/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/03/06 18:52:57 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

static int	get_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

long	ft_atoi2(const char *str)
{
	int		i;
	long	x;
	int		sign;

	i = 0;
	x = 0;
	if (!str || !str[0])
		ft_error();
	sign = get_sign(str, &i);
	if (str[i] < '0' || str[i] > '9')
		ft_error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		x = (x * 10) + (str[i] - '0');
		if ((sign == 1) && (x > INT_MAX))
			ft_error();
		if ((sign == -1) && (-x < INT_MIN))
			ft_error();
		i++;
	}
	if (str[i] != '\0')
		ft_error();
	return (x * sign);
}

/*long	ft_atoi2(const char *str)
{
	int		i;
	long	x;
	int		sign;

	i = 0;
	x = 0;
	sign = 1;
	if (!str || !str[0])
		ft_error();
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		ft_error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		x = (x * 10) + (str[i] - '0');
		if (sign == 1 && x > INT_MAX)
			ft_error();
		if (sign == -1 && -x < INT_MIN)
			ft_error();
		i++;
	}
	if (str[i] != '\0')
		ft_error();
	return (x * sign);
}
*/