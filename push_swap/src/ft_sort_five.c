/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/01/27 11:00:27 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_min_to_b(t_stack **a, t_stack **b)
{
	int		pos;
	int		n;
	long	min;

	min = ft_min(*a);
	pos = ft_pos_of_value(*a, min);
	n = ft_stack_size(*a);
	if (pos <= n / 2)
	{
		while ((*a)->nbr != min)
			ft_ra(a, 0);
	}
	else
	{
		while ((*a)->nbr != min)
			ft_rra(a, 0);
	}
	ft_pb(a, b, 0);
}

void	ft_sort_five(t_stack **a, t_stack **b)
{
	if (!a || !*a)
		return ;
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	ft_sort_three(a);
	ft_pa(a, b, 0);
	ft_pa(a, b, 0);
	if ((*a)->nbr > (*a)->next->nbr)
		ft_sa(a, 0);
}
