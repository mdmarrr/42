#include "../include/push_swap.h"
#include <stdio.h>

/* -------- DEBUG PRINT -------- */

void	print_stack(t_stack *stack, char *name)
{
	printf("%s: ", name);
	while (stack)
	{
		printf("%ld ", stack->nbr);
		stack = stack->next;
	}
	printf("\n");
}

/* -------- BUILD STACK MANUALLY -------- */

t_stack	*build_stack(long a, long b, long c)
{
	t_stack	*stack;

	stack = NULL;
	ft_add_back(&stack, ft_stack_new(a));
	ft_add_back(&stack, ft_stack_new(b));
	ft_add_back(&stack, ft_stack_new(c));
	return (stack);
}

/* -------- MAIN TEST -------- */

int	main(void)
{
	t_stack	*a;
	t_stack	*b;

	a = build_stack(1, 2, 3);
	b = NULL;

	printf("Initial state:\n");
	print_stack(a, "A");
	print_stack(b, "B");

	printf("\n-- sa --\n");
	ft_sa(&a, 1);
	print_stack(a, "A");

	printf("\n-- ra --\n");
	ft_ra(&a, 1);
	print_stack(a, "A");

	printf("\n-- rra --\n");
	ft_rra(&a, 1);
	print_stack(a, "A");

	printf("\n-- pb --\n");
	ft_pb(&a, &b, 1);
	print_stack(a, "A");
	print_stack(b, "B");

	printf("\n-- pa --\n");
	ft_pa(&a, &b, 1);
	print_stack(a, "A");
	print_stack(b, "B");

	ft_free(&a);
	ft_free(&b);

	return (0);
}
