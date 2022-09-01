# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 15:46:49 by yshimoda          #+#    #+#              #
#    Updated: 2022/09/01 12:59:52 by yshimoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c
CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I 
NAME		= libftprintf.a

all:		$(NAME)

clean:

fclean:

re:

.PHONY:		all clean fclean re bonus