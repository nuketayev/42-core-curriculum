#include "includes/push_swap.h"

void	index_stack(t_stack_node **stack)
{
	t_stack_node	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}

void	init_new_stack(t_stack_node **stack, int argc, char **argv)
{
	t_stack_node	*new;
	char	**temp;
	int		a;

	a = 0;
	if (argc == 2)
		temp = ft_split(argv[1], ' ');
	else
	{
		a = 1;
		temp = argv;
	}
	while (temp[a])
	{
		new = ft_listnew(ft_atol(temp[a]));
		ft_listadd_back(stack, new);
		a++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(temp);
}