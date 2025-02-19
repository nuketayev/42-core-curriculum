/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:18:24 by anuketay          #+#    #+#             */
/*   Updated: 2024/07/30 19:18:25 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push(t_stack_node **stack_to, t_stack_node **stack_from)
{
	t_stack_node	*tmp;
	t_stack_node	*head_to;
	t_stack_node	*head_from;

	if (ft_listsize(*stack_from) == 0)
		return (1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}

int	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pb", 1);
	return (0);
}
