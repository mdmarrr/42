/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/01/27 11:00:27 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = ft_parse(argc, argv);
	if (!a)
		return (0);
	if (check_sorted(a))
	{
		ft_free(&a);
		return (0);
	}
	ft_sort(&a);
	ft_free(&a);
	return (0);
}

//cc src/*.c libft/libft.a -I include -I libft -Wall -Wextra -Werror -o push_swap
