#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
#include <limits.h>

typedef struct s_stack_node
{
	int				value;
	int				index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

void	arg_check(int argc, char **argv);
void	ft_error(char *msg);
void	ft_free(char **str);
void	index_stack(t_stack_node **stack);

t_stack_node	*ft_listnew(int value);
void	ft_listadd_front(t_stack_node **stack, t_stack_node *new);
t_stack_node	*ft_listlast(t_stack_node *head);
void	ft_listadd_back(t_stack_node **stack, t_stack_node *new);
int		ft_listsize(t_stack_node *head);

int		find_smallest(t_stack_node **stack, int val);
void	sort_three_numbers(t_stack_node **stack_a);
void	sort_four_numbers(t_stack_node **stack_a, t_stack_node **stack_b);
void	sort_five_numbers(t_stack_node **stack_a, t_stack_node **stack_b);
void	five_nb_sort(t_stack_node **stack_a, t_stack_node **stack_b, int size);

void	ft_error(char *msg);
void	ft_check_args(int argc, char **argv);
int		is_sorted(t_stack_node **stack);
int		get_distance(t_stack_node **stack, int index);
void	free_stack(t_stack_node **stack);
void	ft_free(char **str);

void	stack_sort(t_stack_node **stack_a, t_stack_node **stack_b);

int		swap(t_stack_node **stack);
int		push(t_stack_node **stack_to, t_stack_node **stack_from);
int		rotate(t_stack_node **stack);
int		reverse_rotate(t_stack_node **stack);

int		sa(t_stack_node **stack_a);
int		sb(t_stack_node **stack_b);
int		ss(t_stack_node **stack_a, t_stack_node **stack_b);
int		pa(t_stack_node **stack_a, t_stack_node **stack_b);
int		pb(t_stack_node **stack_b, t_stack_node **stack_a);
int		ra(t_stack_node **stack_a);
int		rb(t_stack_node **stack_b);
int		rr(t_stack_node **stack_a, t_stack_node **stack_b);
int		rra(t_stack_node **stack_a);
int		rrb(t_stack_node **stack_b);
int		rrr(t_stack_node **stack_a, t_stack_node **stack_b);

#endif