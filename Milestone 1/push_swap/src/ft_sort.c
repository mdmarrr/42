/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/03/06 18:49:53 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort(t_stack **a)
{
	t_stack	*b;
	int		n;

	b = NULL;
	if (!a || !*a || check_sorted(*a))
		return ;
	n = ft_stack_size(*a);
	if (n == 2)
	{
		if ((*a)->nbr > (*a)->next->nbr)
			ft_sa(a, 0);
	}
	else if (n == 3)
		ft_sort_three(a);
	else if (n == 4)
		ft_sort_four(a, &b);
	else if (n == 5)
		ft_sort_five(a, &b);
	else
		ft_sort_big(a);
	ft_free(&b);
}
