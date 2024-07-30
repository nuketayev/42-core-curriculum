LIBFT_DIR    = libft/
LIBFT_NAME   = libft.a
LIBFT        = $(LIBFT_DIR)$(LIBFT_NAME)

NAME         = push_swap
CC           = cc
FLAGS        = -Wall -Werror -Wextra -g
SRC          = handle_errors.c free_error.c ft_list.c instructions/push.c \
               instructions/reverse_rotate.c instructions/rotate.c five_sort/snb_sort.c \
               five_sort/ffnb_sort.c five_sort/five_nb_sort.c big_stack_sort.c \
               instructions/swap.c push_swap.c init_new_stack.c is_sorted.c calculate.c\

OBJ          = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@$(RM) $(NAME)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(MLXFLAGS) $(LIBFT)  -s

clean:
	@make clean -s -C $(LIBFT_DIR)
	@$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@$(RM) $(LIBFT_DIR)$(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
