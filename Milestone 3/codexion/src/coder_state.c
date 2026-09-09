/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:04:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/09/09 16:54:03 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

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
