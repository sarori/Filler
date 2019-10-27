FILL	=	sapark.filler

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

INCLUDE	=	-Iincludes

SRC		=	$(wildcard src/filler/*.c)
OBJ		=	$(patsubst src/filler/%.c, obj/filler/%.o, $(SRC))

all		:	$(FILL)

obj/%.o	: 	src/%.c
			@$(CC) $(CFLAGS) $(OPTION) -c -o $@ $< $(INCLUDE)

$(FILL)	:	obj $(OBJ)
			@cd lib && make
			@mv lib/libftprintf.a .
			@$(CC) -o $(FILL) $(CFLAGS) $(OBJ) libftprintf.a
			@echo "excutable file $(FILL) has been made"

obj		:
			@mkdir obj
			@mkdir obj/filler
			
clean	:
			-cd lib && make clean
			-rm -rf obj

fclean	:	clean
			-rm -f $(FILL)
			-rm -f libftprintf.a

re		:	fclean $(FILL)

.PHONY	:	clean fclean re
