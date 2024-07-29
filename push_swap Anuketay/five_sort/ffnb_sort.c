#include "../includes/push_swap.h"

void	sort_four_numbers(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = calculate_disctance(stack_a, find_smallest(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_three_numbers(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five_numbers(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	distance;

	distance = calculate_disctance(stack_a, find_smallest(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_four_numbers(stack_a, stack_b);
	pa(stack_a, stack_b);
}
