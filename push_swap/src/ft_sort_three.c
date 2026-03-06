/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/03/06 18:55:56 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_three(t_stack **a)
{
	long	x;
	long	y;
	long	z;

	if (!a || !*a || !(*a)->next || !(*a)->next->next || check_sorted(*a))
		return ;
	x = (*a)->nbr;
	y = (*a)->next->nbr;
	z = (*a)->next->next->nbr;
	if (x > y && y < z && x < z)
		ft_sa(a, 0);
	else if (x > y && y > z)
	{
		ft_sa(a, 0);
		ft_rra(a, 0);
	}
	else if (x > y && y < z && x > z)
		ft_ra(a, 0);
	else if (x < y && y > z && x < z)
	{
		ft_sa(a, 0);
		ft_ra(a, 0);
	}
	else if (x < y && y > z && x > z)
		ft_rra(a, 0);
}
