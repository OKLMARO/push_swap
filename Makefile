# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/11 03:32:56 by oamairi           #+#    #+#              #
#    Updated: 2025/07/12 13:13:13 by oamairi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	algo_utils.c algo.c command_stack_a.c command_stack_b.c command_stack.c \
		push_swap.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all