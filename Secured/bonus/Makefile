##
## EPITECH PROJECT, 2023
## B-CPE-110-STG-1-1-secured-titouan.pradoura
## File description:
## Makefile
##
.SILENT:

CFILES := hash.c \

OFILES := $(CFILES:.c=.o)

NAME := hash

all: $(NAME)

$(NAME): $(OFILES)
	@gcc -o $(NAME) $(OFILES)

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all
