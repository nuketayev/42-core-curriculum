#include "includes/push_swap.h"

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