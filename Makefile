NAME = pipex
FLAGS = -Wall -Wextra -Werror
SRCS = src/main.c src/path_ex.c src/tools.c src/children.c
OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:src/%.c=%.o))
LIBFT = ./libft/libft.a

# Cible par défaut
all: $(NAME)

# Cible pour lier les fichiers objets et créer le binaire
$(NAME): $(OBJS) $(LIBFT)
	@echo "Linking $(NAME)..."
	@cc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Créer le répertoire obj si nécessaire
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# Compiler chaque fichier source en fichier objet
$(OBJS_DIR)/%.o: src/%.c | $(OBJS_DIR)
	@echo "Compiling $<..."
	@cc $(FLAGS) -c $< -o $@

# Règle pour la librairie libft
$(LIBFT):
	@make -C ./libft

# Nettoyage des fichiers objets et du binaire
clean: 
	@rm -rf $(OBJS_DIR)
	@make -C ./libft clean

# Nettoyage complet, y compris la libft
fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean

# Reconstruction complète
re: fclean all
