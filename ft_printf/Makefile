LIB_NAME	=	libftprintf.a

SRCS	=	ft_printf.c		src.c

HEADER	=	ft_printf.h
OBJ		=	$(SRCS:%.c=%.o)
CC		=	cc
FLAGS	=	-Wall -Wextra -Werror -I $(HEADER)

all	:	$(LIB_NAME)
$(LIB_NAME)	:	$(OBJ)
	ar rcs $(LIB_NAME) $?

%.o :	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(LIB_NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
