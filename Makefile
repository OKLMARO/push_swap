# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/11 03:32:56 by oamairi           #+#    #+#              #
#    Updated: 2025/08/02 17:04:57 by oamairi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	algo_utils.c algo.c command_stack_a.c command_stack_b.c command_stack.c \
		push_swap.c push_swap_utils.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft bonus
	$(MAKE) -C ft_printf
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re