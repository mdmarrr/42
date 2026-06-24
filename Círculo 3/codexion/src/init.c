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
	data->number_of_coders = atoi(argv[1]);
	data->time_to_burnout = atoi(argv[2]);
	data->time_to_compile = atoi(argv[3]);
	data->time_to_debug = atoi(argv[4]);
	data->time_to_refactor = atoi(argv[5]);
	data->number_of_compiles_required = atoi(argv[6]);
	data->dongle_cooldown = atoi(argv[7]);
	if (strcmp(argv[8], "fifo") == 0)
		data->scheduler = 0;
	else if (strcmp(argv[8], "edf") == 0)
		data->scheduler = 1;
	else
		return (1);
	if (init_mutexes(data) != 0)
		return (1);
	data->dongles = malloc(sizeof(t_dongle) * data->number_of_coders);
	if (!data->dongles)
		return (1);
	data->coders = malloc(sizeof(t_coder) * data->number_of_coders);
	if (!data->coders)
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
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->stop_mutex);
		return (1);
	}
	return (0);
}

int	init_dongles(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_coders)
	{
		data->dongles[i].cooldown_until = 0;
		if (pthread_mutex_init(&data->dongles[i].mutex, NULL) != 0)
			return (1);
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
		i++;
	}
	return (0);
}
