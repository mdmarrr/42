/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:04:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/06/24 17:39:56 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 9)
		return (1);
	if (init_data(&data, argv) != 0)
		return (1);
	if (start_simulation(&data) != 0)
	{
		clean_data(&data);
		return (1);
	}
	clean_data(&data);
	return (0);
}
