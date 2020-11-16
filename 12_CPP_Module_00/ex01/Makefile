# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwon <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 18:55:19 by jwon              #+#    #+#              #
#    Updated: 2020/11/10 19:50:41 by jwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= phonebook

SRCS	= main.cpp phonebook.cpp contact.cpp

OBJS	= $(SRCS:.cpp=.o)

CC		= clang++

FLAGS	= -Wall -Wextra -Werror

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) -I .

all: $(NAME)
	
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
