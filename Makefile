# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 10:54:09 by dinunes-          #+#    #+#              #
#    Updated: 2023/05/05 10:54:09 by dinunes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Program name
NAME	= push_swap

# Compiler
CC		= cc
CFLAGS	= -Werror -Wextra -Wall

# Includes
INC			=	-I ./inc/

# Sources
SRC_PATH	=	src/
SRC			=	init.c				\
				main.c				\
				rotate.c			\
				input.c				\
				push.c				\
				sort.c				\
				lists.c				\
				reverse_rotate.c	\
				swap.c				\

SRCS		= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	@echo "Compiling \033[0;91m$(NAME)\033[0;0m..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INC)
	@echo "\033[0;91m$(NAME) \033[0;0mready."

bonus: all

clean:
	@echo "\033[0;0mRemoving \033[0;91m.o \033[0;0mobject files..."
	@rm -rf $(OBJ_PATH)
	@echo "\033[0;91m.o \033[0;0mobject files removed."

fclean: clean
	@echo "\033[0;0mRemoving \033[0;91mpush_swap\033[0;0m..."
	@rm -f $(NAME)
	@echo "\033[0;91mpush_swap \033[0;0mfile removed."

re: fclean all

.PHONY: all re clean fclean