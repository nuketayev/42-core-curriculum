#include "push_swap.h"

int	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*tail;

	if (ft_listsize(*stack) < 2)
		return (1);
	head = *stack;
	tail = ft_listlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rra(t_stack_node **stack_a)
{
	if (reverse_rotate(stack_a) == 1)
		return (1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_stack_node **stack_b)
{
	if (reverse_rotate(stack_b) == 1)
		return (1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if ((rra(stack_a) == 1 || rrb(stack_b) == 1))
	{
		return (1);
	}
	ft_putendl_fd("rrr", 1);
	return (0);
}
