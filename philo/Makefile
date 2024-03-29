# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 11:25:24 by damachad          #+#    #+#              #
#    Updated: 2024/01/16 14:00:29 by damachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ COLORS /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #

RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
PURPLE 	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ COMMANDS /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #
CC = cc
RM = rm -rf

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ FLAGS _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #

# -fsanitize=thread -g -O1

CFLAGS 	= -Wall -Werror -Wextra -pthread -fsanitize=thread -g
MK_FLAG = --no-print-directory

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ PATHS _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #

OBJ_DIR		= objs

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ FILES _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #

NAME 		= philo
FILES 		= main init utils routine utils2 setters getters
SRC 		= $(addsuffix .c, $(FILES))
OBJ 		= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ ARGUMENTS _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #

# If even philos, t_die = t_eat * 2 + 10
# If odd philos, t_die = t_eat * 3 + 10

SIMPLE = 196 520 200 300 5
N_DEFINED = 3 620 200 100 10
DIE_TIME = 99 300 200 200
INVALID = 3 800 200 200 a

# Dying cases
# 31 550 200 200 10
# 24 300 200 110 5

# No dying cases
# 12 410 200 100 5
# 7 400 100 100 6

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ RULES _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "[$(GREEN)$(SBLINK)$(NAME) created$(RESET)]"

$(OBJ_DIR)/%.o : %.c 
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "[$(GREEN)objs directory created$(RESET)]"

clean:
	@$(RM) $(OBJ_DIR) $(OBJ_BNS_DIR)
	@echo "[$(RED)objs removed$(RESET)]"

fclean: clean
	@$(RM) $(NAME) $(NAME_BNS)
	@echo "[$(RED)executables removed$(RESET)]"

re: fclean all

test: $(NAME)
	@./$(NAME) $(SIMPLE)

test_neat: $(NAME)
	@./$(NAME) $(N_DEFINED)
	
test_die: $(NAME)
	@./$(NAME) $(DIE_TIME)

test_invalid: $(NAME)
	@./$(NAME) $(INVALID)

gdb: $(NAME)
	@gdb --args ./$(NAME) $(ARGS)

.PHONY: all clean fclean re test gdb test_neat test_die test_invalid
