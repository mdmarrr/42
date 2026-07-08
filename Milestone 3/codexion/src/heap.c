/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:04:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/06/24 19:43:48 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

static int	has_higher_priority(t_request a, t_request b, int scheduler)
{
	if (scheduler == 0)
		return (a.arrival < b.arrival);
	return (a.deadline < b.deadline);
}

void	heap_push(t_dongle *dongle, t_request request, int scheduler)
{
	int			i;
	t_request	tmp;

	i = dongle->queue_size;
	dongle->queue[i] = request;
	dongle->queue_size++;
	while (i > 0)
	{
		if (!has_higher_priority(dongle->queue[i],
				dongle->queue[(i - 1) / 2], scheduler))
			break ;
		tmp = dongle->queue[i];
		dongle->queue[i] = dongle->queue[(i - 1) / 2];
		dongle->queue[(i - 1) / 2] = tmp;
		i = (i - 1) / 2;
	}
}

t_request	heap_pop(t_dongle *dongle, int scheduler)
{
	t_request	top;
	t_request	tmp;
	int			i;
	int			child;

	top = dongle->queue[0];
	dongle->queue_size--;
	dongle->queue[0] = dongle->queue[dongle->queue_size];
	i = 0;
	while (1)
	{
		child = (i * 2) + 1;
		if (child >= dongle->queue_size)
			break ;
		if (child + 1 < dongle->queue_size
			&& has_higher_priority(dongle->queue[child + 1],
				dongle->queue[child], scheduler))
			child++;
		if (has_higher_priority(dongle->queue[i],
				dongle->queue[child], scheduler))
			break ;
		tmp = dongle->queue[i];
		dongle->queue[i] = dongle->queue[child];
		dongle->queue[child] = tmp;
		i = child;
	}
	return (top);
}
