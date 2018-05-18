# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atastet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 10:37:46 by atastet           #+#    #+#              #
#    Updated: 2018/05/18 15:01:23 by atastet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	fillit

SRC_PATH	=	src/

SRC		=	main.c \
			ft_usage.c \
			read_tetriminos.c \
			simple_check.c \
			second_check.c \
			make_lst_tetriminos.c \
			make_grid.c \
			arrange_tet.c \
			get_size.c \
			free_lst.c

SRC_POS		= 	$(addprefix $(SRC_PATH),$(SRC))

OBJS 		= 	$(SRC:.c=.o)

CC		=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I libft/

all :		$(NAME)

$(NAME) :	$(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L libft -lft

$(OBJS) :	include/fillit.h
	$(CC) $(CFLAGS) -c $(SRC_POS)

%.o		: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean : 
	rm -f $(OBJS)
	make clean -C ./libft/

fclean : clean
	rm -f $(NAME)
	make fclean -C ./libft/

re : fclean all

.PHONY : all re clean fclean
