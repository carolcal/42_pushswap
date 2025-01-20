# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 10:25:21 by cayamash          #+#    #+#              #
#    Updated: 2025/01/20 09:56:28 by cayamash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name of the program
NAME = push_swap
NAME_BONUS = checker

#Compilers and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

#Directories
SRCS = src
BONUS = bonus
INCLUDES = -I lib/ -I src/ -I bonus/ -I includes/ -I .

# Source files and object files
SRC = $(SRCS)/push_swap.c $(SRCS)/check_args.c $(SRCS)/operations.c \
		$(SRCS)/stack_create.c $(SRCS)/stack_utils.c $(SRCS)/find_target.c\
		$(SRCS)/calculate_index.c $(SRCS)/push_to_stack.c
SRC_BONUS = $(BONUS)/checker_bonus.c $(BONUS)/checker_utils_bonus.c \
			$(BONUS)/check_args_bonus.c $(BONUS)/operations_bonus.c \
			$(BONUS)/stack_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

#Library
LIBFT = lib/libft.a

#Rules
all: $(LIBFT) $(NAME)

bonus: $(NAME_BONUS)

#Executable
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile the library
$(LIBFT):
	@make -C lib
	@echo "Library Compiled."

#Clean object files
clean: 
	@make -C lib clean
	rm -f $(OBJ) $(OBJ_BONUS)

#Clean all generated files
fclean: clean
	@make -C lib fclean
	rm -f $(NAME) $(NAME_BONUS)

#Recompile everything
re: fclean all

.PHONY: all clean fclean re

