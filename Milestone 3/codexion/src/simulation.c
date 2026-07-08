/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:04:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/07/02 20:36:58 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

static void	init_last_compile_times(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_coders)
	{
		set_last_compile(&data->coders[i], data->start_time);
		i++;
	}
}

int	start_simulation(t_data *data)
{
	int	i;

	data->start_time = get_time_ms();
	init_last_compile_times(data);
	if (pthread_create(&data->monitor, NULL, monitor_routine, data) != 0)
		return (1);
	i = 0;
	while (i < data->number_of_coders)
	{
		if (pthread_create(&data->coders[i].thread, NULL,
				coder_routine, &data->coders[i]) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < data->number_of_coders)
	{
		pthread_join(data->coders[i].thread, NULL);
		i++;
	}
	pthread_join(data->monitor, NULL);
	return (0);
}
