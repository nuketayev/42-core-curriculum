#include "includes/push_swap.h"

t_stack_node	*ft_listnew(int value)
{
	t_stack_node	*new;

	new = (t_stack_node *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	ft_listadd_front(t_stack_node **stack, t_stack_node *new)
{
	new->next = *stack;
	*stack = new;
}

t_stack_node	*ft_listlast(t_stack_node *head)
{
	t_stack_node	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	ft_listadd_back(t_stack_node **stack, t_stack_node *new)
{
	t_stack_node	*n;

	if (*stack)
	{
		n = ft_listlast(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

int	ft_listsize(t_stack_node *head)
{
	size_t	i;
	t_stack_node	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
