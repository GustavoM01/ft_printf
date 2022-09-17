# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 13:22:11 by gmaldona          #+#    #+#              #
#    Updated: 2022/09/17 19:22:06 by gmaldona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ph_reader.c ph_writer.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a 

LIBFT = libft.a

CC = clang

CFLAGS = -Wall -Werror -Wextra

AR = ar -rcs

ARQ = ar -q

RM = rm -f

$(NAME): $(OBJS)
		$(MAKE) -C libft
		cp ./libft/$(LIBFT) $(NAME)
		$(ARQ) $(NAME) $(OBJS) 
		

all:
		make $(NAME)

clean: 
		$(RM) $(OBJS)
		cd ./libft && $(MAKE) clean

fclean:		clean
		$(RM) $(NAME)
		cd ./libft && $(MAKE) fclean

re:		fclean all
		
.PHONY: all clean fclean re

