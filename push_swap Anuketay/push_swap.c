#include "push_swap.h"

static void	create_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_listnew(ft_atol(args[i]));
		ft_listadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(args);
}

static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_listsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		stack_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc > 1)
	{
	arg_check(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	create_stack(stack_a, argc, argv);
	while(1)
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
