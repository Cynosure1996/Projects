NAME	=	get_next_line.a

SRCS	= 	get_next_line_utils.c	get_next_line.c

HEADER	= 	get_next_line.h

OBJ		=	$(SRCS:%.c=%.o)

OBJ_B	=	$(SRCS_B:%.c=%.o)

CC		= 	gcc
FLAGS	=	 -Wall -Wextra -Werror

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
			ar r $(NAME) $?
			@echo "\033[36;1m\n< Complited get_next_line >\n\033[0m"

%.o 	:	%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

$(OBJ_B)	:	$(SRCS_B) $(HEADER)
			$(CC) $(FLAGS) -c $(SRCS_B)


clean	:
			@rm -rf $(OBJ) $(OBJ_B)

fclean	:	clean
			@rm -f $(NAME)

re		:	fclean all
