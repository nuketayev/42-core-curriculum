#include "includes/push_swap.h"

static int	calculate_max_bits(t_stack_node **stack)
{
	t_stack_node	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	quick_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_listsize(head_a);
	max_bits = calculate_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_listsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
