/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:18:37 by anuketay          #+#    #+#             */
/*   Updated: 2024/07/30 19:41:57 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	swap(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*next;
	int				tmp_val;
	int				tmp_index;

	if (ft_listsize(*stack) < 2)
		return (1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		ft_error("Error");
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	sa(t_stack_node **stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_stack_node **stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
