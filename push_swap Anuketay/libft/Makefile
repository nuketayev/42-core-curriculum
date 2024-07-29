NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar

SRC = ft_atol.c ft_split.c \
	ft_strchr.c ft_substr.c ft_putstr_fd.c \
	ft_isdigit.c ft_strlen.c ft_strdup.c \
	ft_putendl_fd.c ft_putchar_fd.c \

SRCBONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJ = $(SRC:.c=.o)

OBJBONUS = $(SRCBONUS:.c=.o)

$(NAME): $(OBJ)
	$(AR) rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

bonus: $(OBJ) $(OBJBONUS)
	$(AR) rc $(NAME) $(OBJ) $(OBJBONUS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
