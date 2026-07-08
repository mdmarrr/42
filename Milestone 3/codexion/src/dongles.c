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

static void	release_one_dongle(t_coder *coder, t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->mutex);
	dongle->cooldown_until = get_time_ms() + coder->data->dongle_cooldown;
	dongle->in_use = 0;
	pthread_cond_broadcast(&dongle->cond);
	pthread_mutex_unlock(&dongle->mutex);
}

void	drop_dongles(t_coder *coder)
{
	release_one_dongle(coder, coder->left);
	release_one_dongle(coder, coder->right);
}

static int	is_my_turn(t_dongle *dongle, t_coder *coder)
{
	if (dongle->queue_size == 0)
		return (0);
	return (dongle->queue[0].coder == coder);
}

static int	take_one_dongle(t_coder *coder, t_dongle *dongle)
{
	t_request	request;

	request.coder = coder;
	request.arrival = get_time_ms();
	request.deadline = get_last_compile(coder) + coder->data->time_to_burnout;
	pthread_mutex_lock(&dongle->mutex);
	heap_push(dongle, request, coder->data->scheduler);
	while (!get_stop(coder->data) && (!is_my_turn(dongle, coder)
			|| dongle->in_use || get_time_ms() < dongle->cooldown_until))
	{
		pthread_mutex_unlock(&dongle->mutex);
		usleep(500);
		pthread_mutex_lock(&dongle->mutex);
	}
	if (get_stop(coder->data))
	{
		pthread_mutex_unlock(&dongle->mutex);
		return (1);
	}
	heap_pop(dongle, coder->data->scheduler);
	dongle->in_use = 1;
	print_status(coder, "has taken a dongle");
	pthread_mutex_unlock(&dongle->mutex);
	return (0);
}

int	take_dongles(t_coder *coder)
{
	if (coder->id % 2 == 0)
	{
		if (take_one_dongle(coder, coder->right))
			return (1);
		if (take_one_dongle(coder, coder->left))
        {
            release_one_dongle(coder, coder->right);
            return (1);
        }
    }
	else
	{
		if (take_one_dongle(coder, coder->left))
			return (1);
		if (take_one_dongle(coder, coder->right))
		{
			release_one_dongle(coder, coder->left);
            return (1);
		}
	}
	return (0);
}
