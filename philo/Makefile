NAME = philo

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# Couleurs pour les messages
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BLUE = \033[38;2;15;101;214m
RESET = \033[0m

OBJ_PATH = obj/
PARSING_PATH = parsing/
UTIL_PATH = utils/
SRC_PATH = src/
CORE_PATH = core/

SRC = main.c
UTIL = free_all.c utils.c
PARSING = parsing.c ft_utils_node_remains.c ft_utils_node.c parsing2.c gen_utils.c ft_itoa.c
CORE = core.c init.c routines.c starting.c

CORES = $(addprefix $(CORE_PATH), $(CORE))  
SRCS = $(addprefix $(SRC_PATH), $(SRC))
PARSINGS = $(addprefix $(PARSING_PATH), $(PARSING))
UTILS = $(addprefix $(UTIL_PATH), $(UTIL))

OBJ = $(PARSING:.c=.o)
OBJ_UTIL = $(UTIL:.c=.o)
OBJ_SRC = $(SRC:.c=.o)
OBJ_CORE = $(CORE:.c=.o)

OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
OBJS_UTIL = $(addprefix $(OBJ_PATH), $(OBJ_UTIL))
OBJS_SRC = $(addprefix $(OBJ_PATH), $(OBJ_SRC))
OBJS_CORE = $(addprefix $(OBJ_PATH), $(OBJ_CORE))

all: $(NAME)
	@echo ">>> $(BLUE)COMPILATION TERMINEE $(RESET)<<<"

$(NAME): $(OBJS) $(OBJS_SRC) $(OBJS_CORE) $(OBJS_UTIL)
	@$(CC) $(CFLAGS) $(OBJS) $(OBJS_SRC) $(OBJS_CORE) $(OBJS_UTIL) -o $@

$(OBJ_PATH)%.o: $(PARSING_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(CORE_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(UTIL_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo ">>> $(RED)SUPPRESSION DES FICHIERS .o $(RESET)<<<"
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)"
	@echo "$(RESET)"

fclean: clean
	@echo ">>> $(RED)SUPPRESSION DE L'EXECUTABLE $(RESET)<<<"
	@rm -f $(NAME)
	
re: fclean all
	@echo "$(RESET)"

.PHONY: all clean fclean re
