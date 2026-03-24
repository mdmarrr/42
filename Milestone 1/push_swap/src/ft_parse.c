/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/03/06 18:42:29 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

t_stack	*ft_parse_args_quoted(char **argv)
{
	t_stack	*a;
	char	**tmp;

	a = NULL;
	tmp = ft_split(argv[1], ' ');
	if (!tmp)
		ft_error();
	if (!tmp[0])
	{
		ft_freestr(tmp);
		ft_error();
	}
	list_args(tmp, &a, 0);
	ft_freestr(tmp);
	return (a);
}

t_stack	*ft_parse(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	if (argc < 2)
		return (NULL);
	if (argc == 2)
		a = ft_parse_args_quoted(argv);
	else
		list_args(argv, &a, 1);
	if (a && ft_checkdup(a))
	{
		ft_free(&a);
		ft_error();
	}
	return (a);
}

int	ft_checkdup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

void	list_args(char **argv, t_stack **a, int start)
{
	int		i;
	long	val;

	i = start;
	while (argv[i])
	{
		val = ft_atoi2(argv[i]);
		ft_add_back(a, ft_stack_new((int)val));
		i++;
	}
}

void	ft_freestr(char **lst)
{
	int	i;

	if (!lst)
		return ;
	i = 0;
	while (lst[i])
	{
		free(lst[i]);
		i++;
	}
	free(lst);
}
