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

void	clean_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->dongles_initialized)
	{
		pthread_mutex_destroy(&data->dongles[i].mutex);
		pthread_cond_destroy(&data->dongles[i].cond);
		free(data->dongles[i].queue);
		i++;
	}
	i = 0;
	while (i < data->coders_initialized)
	{
		pthread_mutex_destroy(&data->coders[i].state_mutex);
		i++;
	}
	if (data->stop_mutex_initialized)
		pthread_mutex_destroy(&data->stop_mutex);
	if (data->print_mutex_initialized)
		pthread_mutex_destroy(&data->print_mutex);
	free(data->dongles);
	free(data->coders);
}
