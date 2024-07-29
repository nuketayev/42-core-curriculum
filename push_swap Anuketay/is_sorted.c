#include "includes/push_swap.h"

int	is_sorted(t_stack_node **stack)
{
	t_stack_node	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}