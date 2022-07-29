# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 10:11:18 by armaxima          #+#    #+#              #
#    Updated: 2021/12/01 20:23:58 by armaxima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -MMD -Wall -Wextra -Werror

NAME = push_swap

SRC = src/main.c \
	src/ft_utils.c \
	src/ft_check_argv.c \
	src/ft_create_stack_b.c \
	src/ft_create_list.c \
	src/ft_move.c \
	src/ft_find_flag.c \
	src/ft_strdup_sw.c \
	src/ft_put_moving.c \
	src/ft_swap.c \
	src/ft_find_stack.c

LIBFT = ./libft/

HEADER = ./include/push_swap.h

OBJ = $(SRC:.c=.o)

SRC_D = $(SRC:.c=.d)

%.o : %.c
	gcc $(FLAG) -c $< -o $@ -I $(LIBFT)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) $(LIBFT)libft.a
	gcc $(FLAG) $(OBJ) -o $(NAME) -I includes -L $(LIBFT) -lft

$(LIBFT)libft.a: $(LIBFT)Makefile $(LIBFT)libft.h
	@make -C $(LIBFT) all && make -C $(LIBFT) bonus
	@echo "libft created"

clean:
	make -C $(LIBFT) clean
	rm -f $(OBJ) $(SRC_D)

fclean: clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
