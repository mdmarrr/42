/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/01/27 11:37:13 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate_b_to_top(t_stack **b, long target_index)
{
	int		pos;
	int		n;
	t_stack	*tmp;

	pos = 0;
	tmp = *b;
	while (tmp && tmp->index != target_index)
	{
		pos++;
		tmp = tmp->next;
	}
	n = ft_stack_size(*b);
	if (pos <= n / 2)
	{
		while ((*b)->index != target_index)
			ft_rb(b, 0);
	}
	else
	{
		while ((*b)->index != target_index)
			ft_rrb(b, 0);
	}
}

static long	find_max_index(t_stack *b)
{
	long	max;

	max = b->index;
	while (b)
	{
		if (b->index > max)
			max = b->index;
		b = b->next;
	}
	return (max);
}

static void	push_chunks_to_b(t_stack **a, t_stack **b, int chunk)
{
	int	pushed;
	int	n;

	pushed = 0;
	n = ft_stack_size(*a);
	while (pushed < n)
	{
		if ((*a)->index <= pushed)
		{
			ft_pb(a, b, 0);
			ft_rb(b, 0);
			pushed++;
		}
		else if ((*a)->index <= pushed + chunk)
		{
			ft_pb(a, b, 0);
			pushed++;
		}
		else
			ft_ra(a, 0);
	}
}

void	ft_sort_big(t_stack **a)
{
	t_stack	*b;
	int		n;
	int		chunk;
	long	maxi;

	if (!a || !*a)
		return ;
	b = NULL;
	ft_set_index(*a);
	n = ft_stack_size(*a);
	if (n <= 100)
		chunk = 15;
	else
		chunk = 35;
	push_chunks_to_b(a, &b, chunk);
	while (b)
	{
		maxi = find_max_index(b);
		rotate_b_to_top(&b, maxi);
		ft_pa(a, &b, 0);
	}
}
