#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

static int	ft_duplicate(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
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

void	error_n_free(char **args)
{
	ft_free(args);
	ft_error("Error");
}

void	arg_check(int argc, char **argv)
{
	int		i;
	long		tmp;
	char	**args;

	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
        if (!args[0]) 
			error_n_free(args);
	}
	else
	{
		i = 1;
		args = argv;
	}
    while (args[i]) {
        if (!ft_isnum(args[i]))
            error_n_free(args);
		tmp = ft_atoi(args[i]);
        printf("tmp: %ld\n", tmp);
        if (tmp < INT_MIN || tmp > INT_MAX)
			error_n_free(args);
        if (ft_duplicate(tmp, args, i))
			error_n_free(args);
        i++;
    }
	if (argc == 2)
		ft_free(args);
}
