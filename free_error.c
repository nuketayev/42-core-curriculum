/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:17:23 by anuketay          #+#    #+#             */
/*   Updated: 2024/07/30 19:34:18 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(0);
}

void	error_n_free(char **args, int is_allocated)
{
	if (is_allocated)
		ft_free(args);
	ft_error("Error");
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i > 0)
		free(str[--i]);
	free(str);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}
