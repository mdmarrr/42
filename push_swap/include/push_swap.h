/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/01/27 11:56:48 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include <../libft/libft.h>

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		check_error(char **argv, int i, int j);
int		check_error(char **argv, int i, int j);
int		check_args(char **argv);
int		ft_check_dup(t_stack *a);
int		ft_check_sorted(t_stack *stack_a);
void	ft_free(t_stack **lst);
void	ft_parse(int argc, char **argv);

#endif