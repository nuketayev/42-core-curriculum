#include "../includes/push_swap.h"

void	five_nb_sort(t_stack_node **stack_a, t_stack_node **stack_b, int size)
{
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three_numbers(stack_a);
	else if (size == 4)
		sort_four_numbers(stack_a, stack_b);
	else if (size == 5)
		sort_five_numbers(stack_a, stack_b);
}