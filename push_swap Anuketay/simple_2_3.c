#include "push_swap.h"

int	get_min(t_stack_node **stack, int val)
{
	t_stack_node	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

static void	sort_case_2(t_stack_node **stack_a, int min)
{
	if ((*stack_a)->next->index == min)
		sa(stack_a);
	else
		rra(stack_a);
}

static void	sort_case_3(t_stack_node **stack_a, int min)
{
	if ((*stack_a)->next->index == min)
		ra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_3(t_stack_node **stack_a)
{
	t_stack_node	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (is_sorted(stack_a))
		return ;
	if (head->index == min && head->next->index != next_min)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (head->index == next_min)
		sort_case_2(stack_a, min);
	else
		sort_case_3(stack_a, min);
}

void	simple_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	size;

	if (is_sorted(stack_a) || ft_listsize(*stack_a) == 0
		|| ft_listsize(*stack_a) == 1)
		return ;
	size = ft_listsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
