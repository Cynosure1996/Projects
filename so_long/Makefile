NAME	=	so_long

#SRCS	=	$(wildcard src/*.c)
SRCS	=	src/main.c src/controls.c src/utils.c src/map_init.c \
			src/map_make.c src/errors.c src/enemy_move.c
#SRCS	=	so_long.c	so_long_check.c	so_long_utils.c
#DIR		=	src/

OBJ		=	$(SRCS:%.c=%.o)


GNL		=	get_next_line/get_next_line.a

FTP		=	ft_printf/libftprintf.a

HEADER	=	so_long.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		= rm -rf

MLX 	= -framework OpenGL -framework AppKit -lmlx
#---------------------------------------------------------------------------------
RED		=	\033[1;31m
BLUE	=	\033[1;34m
YELLOW	=	\033[1;33m
WHITE	=	\033[1;32m
PUPURE	=	\033[1;35m
GRY		=	\033[1;30m
TURQUOISE =	\033[36;1m
END		=	\033[0m
#---------------------------------------------------------------------------------
.PHONY:		all	clean	fclean	re	ft_printf

all:		ft_printf GNL $(NAME)


GNL:
			@$(MAKE) -C get_next_line/
ft_printf:
			@$(MAKE) -C ft_printf/

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) $(GNL) $(FTP) $(MLX) -o $(NAME)
			@echo "$(TURQUOISE)\n< Complited $(NAME) >\n$(END)"

%.o :		%.c $(INCLUDE)$(HEADER)
			$(CC) $(FLAGS)  -c $< -o $@ -I $(INCLUDE)


clean:
			@$(RM) $(OBJ)
			@$(MAKE) -C get_next_line/ clean
			@$(MAKE) -C ft_printf/ clean
			@echo "$(YELLOW)\n< Cleaning succeed >\n$(END)"

fclean:		clean
			@$(MAKE) -C get_next_line/ fclean
			@$(MAKE) -C ft_printf/ fclean
			@$(RM) $(NAME)
			@echo "$(YELLOW)\n< All created files were deleted >\n$(END)"

re:			fclean all
			@echo "$(BLUE)\n< Remake done >\n$(END)"
