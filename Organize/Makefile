##
## EPITECH PROJECT, 2023
## B-CPE-110-STG-1-1-organized-camille.billard
## File description:
## Makefile
##

.SILENT:

SRC	=	src/my.c\
		src/put.c\
		src/add.c\
		src/del.c\
		src/cmp.c\
		src/rcmp.c\
		src/sort.c\
		src/main.c\
		src/list.c\
		src/disp.c\
		src/quicksort.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	organized

CFLAGS	=	-g -Wall -Wextra -Wconversion

LIBFLAGS = 	-Llibshell/ -lshell

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIBFLAGS) $(CFLAGS)
	printf "[%s] — Successfully compiled\n" $(NAME)

clean:
	rm $(OBJ) -f

fclean: clean
	rm $(NAME) -f

re:    fclean all
