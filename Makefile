FLAGS = -Werror -Wall -Wextra

NAME = dkotlyar.filler 

FILES = main.c \
		filler.c

OBJSRC = $(FILES:.c=.o)

OBJ = $(addprefix obj/, $(OBJSRC))
SRC = $(addprefix src/, $(FILES))

.PHONY: re all clean fclean

all: $(NAME)

$(NAME):
	@make -C libft/
	@mkdir obj
	@gcc $(FLAGS) -c $(SRC) -I includes
	@mv filler.o obj/
	@mv main.o obj/
	@gcc -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a -I includes 
	@echo "\033[32mCreated filler executable\033[0m"

clean:
	@/bin/rm -rf $(OBJ) obj
	@make -C libft/ fclean
	@echo "\033[31mRemoved filler object files\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mRemoved filler executable\033[0m"

re: fclean all
