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

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str[0])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	check_numeric_args(char **argv)
{
	if (!is_valid_number(argv[1]) || !is_valid_number(argv[2])
		|| !is_valid_number(argv[3]) || !is_valid_number(argv[4])
		|| !is_valid_number(argv[5]) || !is_valid_number(argv[6])
		|| !is_valid_number(argv[7]))
		return (1);
	return (0);
}

static int	check_values(t_data *data)
{
	if (data->number_of_coders <= 0)
		return (1);
	if (data->time_to_burnout <= 0 || data->time_to_compile < 0
		|| data->time_to_debug < 0 || data->time_to_refactor < 0)
		return (1);
	if (data->number_of_compiles_required <= 0)
		return (1);
	if (data->dongle_cooldown < 0)
		return (1);
	return (0);
}

int	parse_args(t_data *data, char **argv)
{
	if (check_numeric_args(argv) != 0)
		return (1);
	data->number_of_coders = atoi(argv[1]);
	data->time_to_burnout = atoi(argv[2]);
	data->time_to_compile = atoi(argv[3]);
	data->time_to_debug = atoi(argv[4]);
	data->time_to_refactor = atoi(argv[5]);
	data->number_of_compiles_required = atoi(argv[6]);
	data->dongle_cooldown = atoi(argv[7]);
	if (check_values(data) != 0)
		return (1);
	if (strcmp(argv[8], "fifo") == 0)
		data->scheduler = 0;
	else if (strcmp(argv[8], "edf") == 0)
		data->scheduler = 1;
	else
		return (1);
	return (0);
}
