/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:04:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/07/02 20:31:35 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

int	get_stop(t_data *data)
{
	int	value;

	pthread_mutex_lock(&data->stop_mutex);
	value = data->stop;
	pthread_mutex_unlock(&data->stop_mutex);
	return (value);
}

void	set_stop(t_data *data, int value)
{
	pthread_mutex_lock(&data->stop_mutex);
	data->stop = value;
	pthread_mutex_unlock(&data->stop_mutex);
}

int	all_finished(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_coders)
	{
		if (get_compiles(&data->coders[i]) < data->number_of_compiles_required)
			return (0);
		i++;
	}
	return (1);
}

void	increment_compiles(t_coder *coder)
{
	pthread_mutex_lock(&coder->state_mutex);
	coder->compiles++;
	pthread_mutex_unlock(&coder->state_mutex);
}

int	get_compiles(t_coder *coder)
{
	int	value;

	pthread_mutex_lock(&coder->state_mutex);
	value = coder->compiles;
	pthread_mutex_unlock(&coder->state_mutex);
	return (value);
}

void	set_last_compile(t_coder *coder, long time)
{
	pthread_mutex_lock(&coder->state_mutex);
	coder->last_compile_start = time;
	pthread_mutex_unlock(&coder->state_mutex);
}

long	get_last_compile(t_coder *coder)
{
	long	time;

	pthread_mutex_lock(&coder->state_mutex);
	time = coder->last_compile_start;
	pthread_mutex_unlock(&coder->state_mutex);
	return (time);
}
