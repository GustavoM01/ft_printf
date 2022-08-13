# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 13:22:11 by gmaldona          #+#    #+#              #
#    Updated: 2022/08/13 21:15:04 by gmaldona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ph_handler.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = clang

FLAGS = -Wall -Werror -Wextra

AR = ar rcs

RM = rm -f

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)
		cd ./libft && $(MAKE)

all: $(NAME)

clean: 
		$(RM) $(OBJS)
		cd ./libft && $(MAKE) clean

fclean:		clean
		$(RM) $(NAME)
		cd ./libft && $(MAKE) fclean

re:		fclean all

.PHONY: all clean fclean re

