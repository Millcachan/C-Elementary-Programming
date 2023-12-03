##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC     =   src/map.c\
			src/main.c\
			src/generator.c\
            src/put_fonction.c\

OBJ	    =	$(SRC:.c=.o)

NAME    =	setting_up

CFLAGS  = -g -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
