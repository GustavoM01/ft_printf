# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 13:22:11 by gmaldona          #+#    #+#              #
#    Updated: 2022/10/01 23:16:21 by gmaldona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ph_reader.c ph_writer.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a 

LIBFT = libft.a

CC = clang

CFLAGS = -Wall -Werror -Wextra

AR = ar -rcs

ARRU = ar -ru

RM = rm -f

$(NAME): 	$(OBJS)
		$(MAKE) -C ./libft aux
		$(ARRU) $(NAME) $(OBJS) 
		

all:
		make $(NAME)

clean: 
		$(RM) $(OBJS)
		cd ./libft && $(MAKE) clean

fclean:		clean
		$(RM) $(NAME)
		cd ./libft && $(MAKE) fclean

re:		fclean all

bonus:
		make $(NAME)
		
.PHONY: all clean fclean re bonus

