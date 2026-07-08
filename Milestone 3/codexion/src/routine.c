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

static int	do_compile(t_coder *coder)
{
	if (take_dongles(coder))
		return (1);
	if (get_stop(coder->data))
	{
		drop_dongles(coder);
		return (1);
	}
	set_last_compile(coder, get_time_ms());
	print_status(coder, "is compiling");
	smart_sleep(coder->data, coder->data->time_to_compile);
	increment_compiles(coder);
	drop_dongles(coder);
	if (all_finished(coder->data))
		set_stop(coder->data, 1);
	return (get_stop(coder->data));
}

void	*coder_routine(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	if (coder->data->number_of_coders == 1)
	{
		pthread_mutex_lock(&coder->left->mutex);
		print_status(coder, "has taken a dongle");
		while (!get_stop(coder->data))
			usleep(1000);
		pthread_mutex_unlock(&coder->left->mutex);
		return (NULL);
	}
	while (!get_stop(coder->data))
	{
		if (do_compile(coder))
			return (NULL);
		print_status(coder, "is debugging");
		smart_sleep(coder->data, coder->data->time_to_debug);
		if (get_stop(coder->data))
			return (NULL);
		print_status(coder, "is refactoring");
		smart_sleep(coder->data, coder->data->time_to_refactor);
	}
	return (NULL);
}
