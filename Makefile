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
INC			=	-I ./includes/

# Sources
SRC_PATH	=	src/
SRC			=	main.c \
				utils.c \
				init.c
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
	@echo "Compiling push_swap..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INC) -lXext -lX11 -lm
	@echo "push_swap ready."

bonus: all

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@echo "Removing push_swap..."
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean