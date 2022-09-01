# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 15:46:49 by yshimoda          #+#    #+#              #
#    Updated: 2022/09/01 16:58:02 by yshimoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c

LIBFTDIR	= libft

OBJS		= $(SRCS:.c=.o)

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -I ft_printf.h

RM			= rm -f

NAME		= libftprintf.a

TESTDIR		= printfTester

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C $(LIBFTDIR)
			cp libft/libft.a $(NAME)
			ar rcs $(NAME) $(OBJS)

clean:
			make clean -C $(LIBFTDIR)
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C $(LIBFTDIR)
			$(RM) $(NAME)

re:			fclean all

test:		make all -C $(TESTDIR)

.PHONY:		all clean fclean re 