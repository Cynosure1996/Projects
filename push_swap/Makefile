NAME		=	push_swap
NAME_B		=	checker

SRCS_FILES	= 	push_swap.c make_arr.c errors.c init.c\
				swap.c push.c rotate.c reverse.c\
				sorting.c stats.c full_sort.c\
				sort_help.c put_a.c

SRCS_B_FILES	= 	make_arr.c errors.c init.c\
				swap.c push.c rotate.c reverse.c\
				checker.c

SRCS		= 	$(SRCS_FILES)
SRCS_B		= 	$(SRCS_B_FILES)
OBJS		=	$(patsubst %.c,%.o,$(SRCS))
OBJS_B		=	$(patsubst %.c,%.o,$(SRCS_B))

INCLUDE		=	-I.

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -f

LIB = ./libft/libft.a

.PHONY:		all libft clean fclean re bonus

all:		libft $(NAME)

libft:
	@$(MAKE) -C $(dir $(LIB))

%.o:		%.c
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME):	$(OBJS) $(LIB)
			$(CC) $(INCLUDE) $(LIB) -o $(NAME) $(OBJS)

bonus:		libft $(OBJS_B) $(LIB)
			$(CC) $(INCLUDE) $(LIB) -o $(NAME_B) $(OBJS_B)

clean:
			@$(RM) $(OBJS) $(OBJS_B)
			@$(MAKE) -C $(dir $(LIB)) clean

fclean:		clean
			@$(MAKE) -C $(dir $(LIB)) fclean
			@$(RM) $(NAME) $(NAME_B)

re:			fclean all
