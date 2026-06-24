/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:04:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/06/24 18:48:27 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void	print_status(t_coder *coder, char *msg)
{
	long	time;

	time = get_time_ms() - coder->data->start_time;
	pthread_mutex_lock(&coder->data->print_mutex);
	printf("%ld %d %s\n", time, coder->id, msg);
	pthread_mutex_unlock(&coder->data->print_mutex);
}
