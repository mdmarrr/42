/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/01/27 13:26:21 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rb(t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = ft_lstlast(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "rb\n", 3);
}

void	ft_sb(t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (j == 0)
		write(1, "sb\n", 3);
}
