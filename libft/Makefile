#################################################
## ARGUMENTS

NAME				= libft.a

CC					= cc
CFLAGS				= -Wall -Werror -Wextra
AR					= ar -rcs


#################################################
## DIRS

OBJ_DIR = ./obj/
INC_DIR = ./inc/
SRC_DIR = ./src/

#################################################
## DIRS

DEF_COLOR = \033[0;90m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m

#################################################
## SOURCES

SRC_FILES			= ft_atoi.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_strchr.c \
					ft_strdup.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_tolower.c \
					ft_toupper.c \
					ft_substr.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_itoa.c \
					ft_strmapi.c \
					ft_striteri.c \
					ft_split.c \
					ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstadd_back.c \
					ft_printf.c \
					ft_printf_extension.c \
					ft_printf_hexa.c \
					ft_printf_pointeur.c \

OBJ_FILES			= $(addprefix ${OBJ_DIR}, ${SRC_FILES:.c=.o}) \

all : ${NAME}

${NAME} : ${OBJ_FILES}
	@${AR} ${NAME} ${OBJ_FILES}
	@echo "${GREEN}${NAME} compiled !${DEF_COLOR}"

${OBJ_DIR}%.o : ${SRC_DIR}%.c | ${OBJ_DIR}
	@${CC} ${CFLAGS} -I ${INC_DIR} -c $< -o $@
	@echo "${YELLOW}Compiling: $< ${DEF_COLOR}"

${OBJ_DIR}:
	@mkdir -p ${OBJ_DIR}

clean :
	@rm -rf ${OBJ_DIR}

fclean : clean
	@rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re bonus