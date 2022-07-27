SOURCES = 	main.c help_thread.c main_help.c init_fill.c \
			thread_manage.c 
OBJECTS =	$(SOURCES:.c=.o)
HEADER = 	philo.h
CC = 		gcc
NAME =		philo
FLAGS =		-Wall -Wextra -Werror #-g -fsanitize=thread
VPATH = 	obj

.PHONY:		all re clean fclean

all:		$(NAME)

$(NAME):	$(OBJECTS)
			$(CC) $(FLAGS) $(addprefix obj/,$(OBJECTS)) $(INCLUDES) -o $@

%.o:		%.c $(HEADER)
			@mkdir -p obj
			$(CC) $(FLAGS) $< -c -o obj/$@

clean:		
			rm -rf obj/

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
