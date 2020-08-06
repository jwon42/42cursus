# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwon <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/03 12:25:28 by jwon              #+#    #+#              #
#    Updated: 2020/05/03 12:31:54 by jwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c \
		  parse.c \
		  print_diuxpsc.c \
		  print_space_zero.c \
		  utils.c

OBJS	= ${SRCS:%.c=%.o}

FLAGS	= -Wall -Wextra -Werror

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I ./
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
