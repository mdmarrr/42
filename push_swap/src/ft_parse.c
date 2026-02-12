/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/01/27 11:37:13 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

long	ft_atoi2(const char *str)
{
	int		i;
	long	x;
	int		sign;

	i = 0;
	x = 0;
	sign = 1;
	if (!str || !str[0])
		ft_error();
	/* NO ignoramos espacios en push_swap */
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		ft_error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		x = (x * 10) + (str[i] - '0');
		if (sign == 1 && x > INT_MAX)
			ft_error();
		if (sign == -1 && -x < INT_MIN)
			ft_error();
		i++;
	}
	/* Si hay cualquier carácter extra imprime error */
	if (str[i] != '\0')
		ft_error();
	return (x * sign);
}

// Function to parse the arguments from the quoted string and send them to list_args function to add them into list.
// With ft_split we split numbers from spaces.
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

// This function does three things.
// 1. It checks if the number of input is less than 2.
// 2. It checks if the number of input is equal to 2.
//    If it is, it means it is a quoted string.
// 3. It checks if the number of input is greater than 2.
//     If it is, it lists the arguements.
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

// This function checks if the stack includes any duplicate numbers
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

// While arguments are valid, we start to add them into stack here one by one with while loop.
// Atoi takes the number and turn it into an integer value where we can make math operations.
// With stack new we create a new node for the current argument without linking it to list.
// We make linking stage in ft_add_back call.
void	list_args(char **argv, t_stack **a, int start)
{
    int     i;
	long	val;

	i = start;
	while (argv[i])
	{
        val = ft_atoi2(argv[i]);
		ft_add_back(a, ft_stack_new((int)val));
		i++;
	}
}

// This function free the string which is the integer values in between quotes.
void	ft_freestr(char **lst)
{
    int i;

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
