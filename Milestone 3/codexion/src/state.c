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
		if (data->coders[i].compiles < data->number_of_compiles_required)
			return (0);
		i++;
	}
	return (1);
}
