/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/01/27 11:00:27 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_three(t_stack **a)
{
	long	x;
	long	y;
	long	z;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	if (check_sorted(*a))
		return ;
	x = (*a)->nbr;
	y = (*a)->next->nbr;
	z = (*a)->next->next->nbr;

	/* Casos:
	   2 1 3 -> sa
	   3 2 1 -> sa + rra
	   3 1 2 -> ra
	   1 3 2 -> sa + ra
	   2 3 1 -> rra
	*/
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
