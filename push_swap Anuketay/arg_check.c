#include "includes/push_swap.h"

void	error_n_free(char **args, int is_allocated)
{
	if (is_allocated)
		ft_free(args);
	ft_error("Error");
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_duplicate(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atol(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

void	arg_check(int argc, char **argv)
{
    int		i;
    long		tmp;
    char	**args;
    int		is_allocated;

    i = 0;
    is_allocated = 0;
    if (argc == 2)
    {
        args = ft_split(argv[1], ' ');
        is_allocated = 1;
        if (!args[0]) 
            error_n_free(args, is_allocated);
    }
    else
    {
        i = 1;
        args = argv;
    }
    while (args[i]) {
        if (!ft_isnum(args[i]))
            error_n_free(args, is_allocated);
        tmp = ft_atol(args[i]);
        if (tmp < INT_MIN || tmp > INT_MAX)
            error_n_free(args, is_allocated);
        if (ft_duplicate(tmp, args, i))
            error_n_free(args, is_allocated);
        i++;
    }
    if (argc == 2)
        ft_free(args);
}
