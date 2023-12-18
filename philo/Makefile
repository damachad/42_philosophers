# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 11:25:24 by damachad          #+#    #+#              #
#    Updated: 2023/12/18 11:15:00 by damachad         ###   ########.fr        #
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
CFLAGS 	= -Wall -Werror -Wextra -g -fsanitize=thread 
MK_FLAG = --no-print-directory

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ PATHS _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #
OBJ_DIR		= objs

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ FILES _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #
NAME 		= philo
FILES 		= main init utils
SRC 		= $(addsuffix .c, $(FILES))
OBJ 		= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ ARGUMENTS _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #
ARGS = 4 450 200 200

# /\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_ RULES _/\_/\_/\_/\_/\_/\_/\_/\_/\_/\_/\ #
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "[$(GREEN)$(NAME) created$(RESET)]"

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
	@./$(NAME) $(ARGS)

gdb: $(NAME)
	@gdb ./$(NAME) $(ARGS)

.PHONY: all clean fclean re test gdb
