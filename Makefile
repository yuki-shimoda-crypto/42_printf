# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 15:46:49 by yshimoda          #+#    #+#              #
#    Updated: 2022/09/01 17:41:12by yshimoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_printf.c\
				ft_put_num.c\
				ft_put_str.c

LIBFTDIR	=	libft

OBJS		=	$(SRCS:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -I ft_printf.h

RM			=	rm -f

NAME		=	libftprintf.a

TESTDIR		=	printfTester

USAMIDIR	=	printf-tester-tokyo

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

test:		all	
			make all -C $(TESTDIR)

usami:		
			make test -C $(USAMIDIR)

.PHONY:		all clean fclean re 