/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:18:10 by anuketay          #+#    #+#             */
/*   Updated: 2024/07/30 19:52:28 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	sort_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	size;

	size = ft_listsize(*stack_a);
	if (size < 2)
		return ;
	if (size <= 5)
		five_nb_sort(stack_a, stack_b, size);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack_node	**stack_a;
	t_stack_node	**stack_b;

	if (argc > 1)
	{
		handle_errors(argc, argv);
		stack_a = (t_stack_node **)malloc(sizeof(t_stack_node));
		stack_b = (t_stack_node **)malloc(sizeof(t_stack_node));
		*stack_a = NULL;
		*stack_b = NULL;
		init_new_stack(stack_a, argc, argv);
		while (1)
		{
			if (is_sorted(stack_a))
			{
				free_stack(stack_a);
				free_stack(stack_b);
				return (0);
			}
			else
				sort_stack(stack_a, stack_b);
		}
	}
	return (0);
}
