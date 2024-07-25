#include "../../inc/push_swap.h"

void free_split(char **split)
{
    size_t i = 0;

    if (!split)
        return;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

void handle_split_argv(int argc, char **argv, t_stack_node **a, char ***split_argv)
{
    if (argc == 2)
    {
        *split_argv = ft_split(argv[1], ' ');
        argv = *split_argv;
    }
    init_stack_a(a, argv + 1);
}

void sort_stack(t_stack_node **a, t_stack_node **b)
{
    if (!stack_sorted(*a))
    {
        if (stack_len(*a) == 2)
            sa(a, false);
        else if (stack_len(*a) == 3)
            sort_three(a);
        else
            sort_stacks(a, b);
    }
}

int main(int argc, char **argv)
{
    t_stack_node *a = NULL;
    t_stack_node *b = NULL;
    char **split_argv = NULL;

    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);

    handle_split_argv(argc, argv, &a, &split_argv);
    sort_stack(&a, &b);

    free_stack(&a);
    free_stack(&b);
    if (split_argv)
        free_split(split_argv);

    return (0);
}
