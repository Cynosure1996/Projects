SOURCES = 	main.c main_help.c time_help.c init_phill.c \
			process_watch.c philo_process.c 
OBJECTS =	$(SOURCES:.c=.o)
HEADER = 	philo.h
CC = 		gcc
NAME =		philo_bonus
FLAGS =		-Wall -Wextra -Werror #-g -fsanitize=thread
VPATH = 	obj

.PHONY:		all re clean fclean libs

all:		$(NAME)

$(NAME):	$(OBJECTS)
			$(CC) $(FLAGS) $(addprefix obj/,$(OBJECTS)) -o $@

%.o:		%.c $(HEADER)
			@mkdir -p obj
			$(CC) $(FLAGS) $< -c -o obj/$@

clean:		
			rm -rf obj/

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
