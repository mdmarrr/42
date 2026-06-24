/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:04:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/06/24 19:43:30 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

int	start_simulation(t_data *data)
{
	data->start_time = get_time_ms();
	print_status(&data->coders[0], "is compiling");
	return (0);
}
