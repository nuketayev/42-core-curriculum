/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snb_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:18:54 by anuketay          #+#    #+#             */
/*   Updated: 2024/07/30 19:41:21 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	int				min;
	int				next_min;

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
