/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:04:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/07/02 20:57:48 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

static void	take_dongles(t_coder *coder)
{
	if (coder->id % 2 == 0)
	{
		pthread_mutex_lock(&coder->right->mutex);
		print_status(coder, "has taken a dongle");
		pthread_mutex_lock(&coder->left->mutex);
		print_status(coder, "has taken a dongle");
	}
	else
	{
		pthread_mutex_lock(&coder->left->mutex);
		print_status(coder, "has taken a dongle");
		pthread_mutex_lock(&coder->right->mutex);
		print_status(coder, "has taken a dongle");
	}
}

static void	drop_dongles(t_coder *coder)
{
	pthread_mutex_unlock(&coder->right->mutex);
	pthread_mutex_unlock(&coder->left->mutex);
}

void	*coder_routine(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	while (!get_stop(coder->data))
	{
		take_dongles(coder);
		print_status(coder, "is compiling");
		usleep(coder->data->time_to_compile * 1000);
		coder->compiles++;
		drop_dongles(coder);
		if (all_finished(coder->data))
			set_stop(coder->data, 1);
		print_status(coder, "is debugging");
		usleep(coder->data->time_to_debug * 1000);
		print_status(coder, "is refactoring");
		usleep(coder->data->time_to_refactor * 1000);
	}
	return (NULL);
}
