/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/03/06 18:50:59 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*find_next_min_unindexed(t_stack *a)
{
	t_stack	*best;

	best = NULL;
	while (a)
	{
		if (a->index == -1)
		{
			if (!best || a->nbr < best->nbr)
				best = a;
		}
		a = a->next;
	}
	return (best);
}

void	ft_set_index(t_stack *a)
{
	long	i;
	t_stack	*node;

	node = a;
	while (node)
	{
		node->index = -1;
		node = node->next;
	}
	i = 0;
	while (1)
	{
		node = find_next_min_unindexed(a);
		if (!node)
			break ;
		node->index = i;
		i++;
	}
}
