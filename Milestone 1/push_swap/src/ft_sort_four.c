/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/01/27 11:00:27 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_pos_of_value(t_stack *a, long v)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->nbr == v)
			return (pos);
		a = a->next;
		pos++;
	}
	return (-1);
}

void	ft_sort_four(t_stack **a, t_stack **b)
{
	int		pos;
	int		n;
	long	min;

	if (!a || !*a)
		return ;
	min = ft_min(*a);
	pos = ft_pos_of_value(*a, min);
	n = ft_stack_size(*a);
	if (pos == -1)
		return ;
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
	ft_sort_three(a);
	ft_pa(a, b, 0);
}
