/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:04:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/07/02 20:38:09 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

static int	check_burnout(t_coder *coder)
{
	long	now;
	long	last;

	now = get_time_ms();
	last = get_last_compile(coder);
	if (now - last > coder->data->time_to_burnout)
	{
		print_status(coder, "burned out");
		set_stop(coder->data, 1);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (!get_stop(data))
	{
		i = 0;
		while (i < data->number_of_coders && !get_stop(data))
		{
			if (check_burnout(&data->coders[i]))
				return (NULL);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
