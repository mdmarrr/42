/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/01/27 13:28:37 by magomez-         ###   ########.fr       */
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

void	fr_sa(t_stack **a, int j);
void	ft_sb(t_stack **b, int j);
void	fr_ss(t_stack **a, t_stack **b, int j);
void	fr_pa(t_stack **a, t_stack **b, int j);
void	ft_pb(t_stack **stack_a, t_stack **stack_b, int j);
void	ft_ra(t_stack **a, int j);
void	ft_rb(t_stack **b, int j);
void	ft_rr(t_stack **a, t_stack **b, int j);
void	fr_rra(t_stack **a, int j);
void	ft_rrb(t_stack **b, int j);
void	ft_rrr2(t_stack **a, t_stack **b, int j);
void	ft_rrr(t_stack **a, t_stack **b, int j);

#endif