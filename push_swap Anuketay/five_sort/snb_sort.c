#include "../includes/push_swap.h"

int	find_smallest(t_stack_node **stack, int val)
{
	t_stack_node	*top;
	int		min;

	top = *stack;
	min = top->index;
	while (top->next)
	{
		top = top->next;
		if ((top->index < min) && top->index != val)
			min = top->index;
	}
	return (min);
}

static void	sort_three_numbers_2(t_stack_node **stack_a, int min)
{
	if ((*stack_a)->next->index == min)
		sa(stack_a);
	else
		rra(stack_a);
}

static void	sort_three_numbers_3(t_stack_node **stack_a, int min)
{
	if ((*stack_a)->next->index == min)
		ra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_three_numbers(t_stack_node **stack_a)
{
	t_stack_node	*top;
	int		min;
	int		next_min;

	top = *stack_a;
	min = find_smallest(stack_a, -1);
	next_min = find_smallest(stack_a, min);
	if (top->index == min)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (top->index == next_min)
		sort_three_numbers_2(stack_a, min);
	else
		sort_three_numbers_3(stack_a, min);
}
