#include "push_swap.h"

int	rotate(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*tail;

	if (ft_listsize(*stack) < 2)
		return (1);
	head = *stack;
	tail = ft_listlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ra(t_stack_node **stack_a)
{
	if (rotate(stack_a) == 1)
		return (1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_stack_node **stack_b)
{
	if (rotate(stack_b) == 1)
		return (1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if ((ra(stack_a) == 1 || rb(stack_b) == 1))
		return (1);
	ft_putendl_fd("rr", 1);
	return (0);
}
