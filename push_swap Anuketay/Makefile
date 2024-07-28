LIBFT_DIR    = libft/
LIBFT_NAME   = libft.a
LIBFT        = $(LIBFT_DIR)$(LIBFT_NAME)

NAME         = push_swap
CC           = cc
FLAGS        = -Wall -Werror -Wextra -g
SRC          = arg_check.c utils.c ft_list.c push.c \
               reverse_rotate.c rotate.c simple_2_3.c \
               simple_4_5.c stack_sort.c stack_index.c \
               swap.c push_swap.c \

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
