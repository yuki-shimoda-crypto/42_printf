SRCS		=	ft_printf.c		\
				ft_put_str.c	\
				ft_put_ptr.c

LIBFTDIR	=	libft

OBJS		=	$(SRCS:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -I ft_printf.h

RM			=	rm -f

NAME		=	libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C $(LIBFTDIR)
			cp libft/libft.a $(NAME)
			ar rcs $(NAME) $(OBJS)

clean:
			make fclean -C $(LIBFTDIR)
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re 