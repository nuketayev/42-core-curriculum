/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:17:39 by anuketay          #+#    #+#             */
/*   Updated: 2024/07/30 20:48:51 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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

void	split_arguments(int argc, char **argv, char ***args, int *is_allocated)
{
	if (argc == 2)
	{
		*args = ft_split(argv[1], ' ');
		*is_allocated = 1;
		if (!(*args)[0])
			error_n_free(*args, *is_allocated);
	}
	else
	{
		*args = argv;
		*is_allocated = 0;
	}
}

void	validate_arguments(char **args, int is_allocated)
{
	int		i;
	long	tmp;

	if (is_allocated)
		i = 0;
	else
		i = 1;
	while (args[i])
	{
		if (!ft_isnum(args[i]))
			error_n_free(args, is_allocated);
		tmp = ft_atol(args[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
			error_n_free(args, is_allocated);
		if (ft_duplicate(tmp, args, i))
			error_n_free(args, is_allocated);
		i++;
	}
}

void	handle_errors(int argc, char **argv)
{
	char	**args;
	int		is_allocated;

	split_arguments(argc, argv, &args, &is_allocated);
	validate_arguments(args, is_allocated);
	if (argc == 2)
		ft_free(args);
}
