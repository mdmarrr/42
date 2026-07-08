/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:04:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/06/24 19:42:30 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

int	init_data(t_data *data, char **argv)
{
	memset(data, 0, sizeof(t_data));
	if (parse_args(data, argv) != 0)
		return (1);
	if (init_mutexes(data) != 0)
		return (1);
	if (init_arrays(data) != 0)
		return (1);
	if (init_dongles(data) != 0)
		return (1);
	if (init_coders(data) != 0)
		return (1);
	return (0);
}

int	init_mutexes(t_data *data)
{
	if (pthread_mutex_init(&data->stop_mutex, NULL) != 0)
		return (1);
	data->stop_mutex_initialized = 1;
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (1);
	data->print_mutex_initialized = 1;
	return (0);
}

int	init_dongles(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_coders)
	{
		data->dongles[i].cooldown_until = 0;
		data->dongles[i].queue_size = 0;
		data->dongles[i].queue_capacity = data->number_of_coders;
		data->dongles[i].queue = malloc(sizeof(t_request) * data->dongles[i].queue_capacity);
		if (!data->dongles[i].queue)
			return (1);
		if (pthread_mutex_init(&data->dongles[i].mutex, NULL) != 0)
			return (1);
		if (pthread_cond_init(&data->dongles[i].cond, NULL) != 0)
			return (1);
		data->dongles[i].in_use = 0;
		data->dongles_initialized++;
		i++;
	}
	return (0);
}

int	init_coders(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_coders)
	{
		data->coders[i].id = i + 1;
		data->coders[i].compiles = 0;
		data->coders[i].last_compile_start = 0;
		data->coders[i].thread = 0;
		data->coders[i].left = &data->dongles[i];
		data->coders[i].right = &data->dongles[(i + 1)
			% data->number_of_coders];
		data->coders[i].data = data;
		if (pthread_mutex_init(&data->coders[i].state_mutex, NULL) != 0)
			return (1);
		data->coders_initialized++;
		i++;
	}
	return (0);
}

int	init_arrays(t_data *data)
{
	data->dongles = malloc(sizeof(t_dongle) * data->number_of_coders);
	if (!data->dongles)
		return (1);
	data->coders = malloc(sizeof(t_coder) * data->number_of_coders);
	if (!data->coders)
	{
		free(data->dongles);
		data->dongles = NULL;
		return (1);
	}
	return (0);
}
