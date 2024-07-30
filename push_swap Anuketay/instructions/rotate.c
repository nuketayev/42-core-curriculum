/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:18:33 by anuketay          #+#    #+#             */
/*   Updated: 2024/07/30 19:18:33 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_stack_node **stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}
