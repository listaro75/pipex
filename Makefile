NAME = pipex
FLAGS = -Wall -Wextra -Werror
SRCS = main.c path_ex.c
LIBFT = ./libft/libft.a 

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)
	cc ${FLAGS} ${SRCS} ${LIBFT} -o ${OBJS}  ${NAME} -g

.c.o:
	@cc $(FLAGS) -c $< -o $@

$(LIBFT):
	@make -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean

clean:
	@rm -rf *.o
	@make -C ./libft clean

re: fclean all