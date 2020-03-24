##
## EPITECH PROJECT, 2019
## makefile infin_add
## File description:
## compile lib etc
##

NAME	=	printf

all:	$(NAME)

$(NAME):	
	make -C ./lib/my
clean:
	rm -f *.o
	rm -f libmy.a
fclean:	clean
	rm -f $(NAME)
re:	fclean all