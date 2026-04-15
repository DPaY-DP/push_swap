# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/13 12:37:24 by marvin            #+#    #+#              #
#    Updated: 2026/04/13 12:37:24 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror 
OBJ_FILES = find_position.c free_all.c ft_split.c helper.c \
insert.c is_sorted.c push_swap.c push.c reverse_rotate.c \
rotate.c sort_algorithm.c sort_tiny.c swap.c
OBJS = $(OBJ_FILES:.c=.o)
PUSH_SWAP = -C push_swap

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all

fclean: clean
	rm -f $(NAME)
	
.PHONY: all clean re fclean