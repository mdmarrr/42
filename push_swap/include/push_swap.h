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

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
}	t_stack;

void	ft_error(void);
void	ft_free(t_stack **lst);
t_stack	*ft_stack_new(int content);
void	ft_add_back(t_stack **stack, t_stack *stack_new);
t_stack	*ft_stack_last(t_stack *lst);
int		ft_stack_size(t_stack *lst);
int		check_sorted(t_stack *a);
long	ft_min(t_stack *a);
long	ft_max(t_stack *a);
void	ft_sa(t_stack **a, int j);
void	ft_sb(t_stack **b, int j);
void	ft_ss(t_stack **a, t_stack **b, int j);
void	ft_pa(t_stack **a, t_stack **b, int j);
void	ft_pb(t_stack **a, t_stack **b, int j);
void	ft_ra(t_stack **a, int j);
void	ft_rb(t_stack **b, int j);
void	ft_rr(t_stack **a, t_stack **b, int j);
void	ft_rra(t_stack **a, int j);
void	ft_rrb(t_stack **b, int j);
void	ft_rrr(t_stack **a, t_stack **b, int j);
long	ft_atoi2(const char *str);
t_stack	*ft_parse_args_quoted(char **argv);
t_stack	*ft_parse(int argc, char **argv);
int		ft_checkdup(t_stack *a);
void	list_args(char **argv, t_stack **a, int start);
void	ft_freestr(char **lst);
void	ft_sort_three(t_stack **a);
void	ft_sort_four(t_stack **a, t_stack **b);
void	ft_sort_five(t_stack **a, t_stack **b);
int		ft_pos_of_value(t_stack *a, long v);
void	ft_sort(t_stack **a);
void	ft_set_index(t_stack *a);
void	ft_sort_big(t_stack **a);

#endif