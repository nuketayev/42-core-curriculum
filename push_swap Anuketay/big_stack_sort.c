/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:18:15 by anuketay          #+#    #+#             */
/*   Updated: 2024/07/30 20:25:20 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	calculate_max_bits(t_stack_node **stack)
{
	t_stack_node	*head;
	int				biggest_index;
	int				bit_count;

	head = *stack;
	biggest_index = head->index;
	bit_count = 0;
	while (head)
	{
		if (head->index > biggest_index)
			biggest_index = head->index;
		head = head->next;
	}
	while ((biggest_index >> bit_count) != 0)
		bit_count++;
	return (bit_count);
}

void	radix_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*tmp_stack_a;
	int				bit;
	int				nb;
	int				size;
	int				max_bits;

	bit = 0;
	tmp_stack_a = *stack_a;
	size = ft_listsize(tmp_stack_a);
	max_bits = calculate_max_bits(stack_a);
	while (bit < max_bits)
	{
		nb = 0;
		while (nb++ < size)
		{
			tmp_stack_a = *stack_a;
			if (((tmp_stack_a->index >> bit) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_listsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		bit++;
	}
}
