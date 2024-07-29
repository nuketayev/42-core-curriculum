#include "includes/push_swap.h"

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

t_stack_node	*get_next_min(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->value < min->value))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

int	calculate_disctance(t_stack_node **stack, int index)
{
	t_stack_node	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}