# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmichel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/21 13:17:34 by lmichel           #+#    #+#              #
#    Updated: 2021/11/21 13:52:45 by lmichel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	commands.c commands_three.c commands_two.c ft_atoi.c ft_big_sort.c ft_big_sort_second_part.c ft_init_arr.c ft_small_sort.c ft_split.c ft_start.c ft_strdup.c lst_utils.c push_swap.c

HEADER	=	push_swap.h
OBJ		=	$(SRCS:%.c=%.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I $(HEADER)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) -o $@

clean	:
	rm -f $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all