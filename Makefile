FLAGS = -Werror -Wall -Wextra

NAME = dkotlyar.filler 

FILES = main.c \
		filler.c \
		first_algo.c 

SECOND += main.c \
		  filler.c \
		  second_algo.c

THIRD += main.c \
		 filler.c \
		 third_algo.c

OBJSRC = $(FILES:.c=.o)

OBJ = $(addprefix obj/, $(OBJSRC))
SRC = $(addprefix src/, $(FILES))
2SRC = $(addprefix src/, $(SECOND))
3SRC = $(addprefix src/, $(THIRD))

.PHONY: re all clean fclean

all: $(NAME)

$(NAME):
	@make -C libft/
	@mkdir obj
	@gcc $(FLAGS) -c $(SRC) -I includes
	@mv filler.o obj/
	@mv main.o obj/
	@mv first_algo.o obj/
	@gcc -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a -I includes 
	@echo "\033[32mCreated filler executable\033[0m"

second: fclean
	@make -C libft/
	@mkdir obj
	@gcc $(FLAGS) -c $(2SRC) -I includes
	@mv filler.o obj/
	@mv main.o obj/
	@mv second_algo.o obj/
	@gcc -o $(NAME) $(FLAGS) obj/main.o obj/filler.o obj/second_algo.o libft/libft.a -I includes
	@echo "\033[32mCreated filler executable\033[0m"

third: fclean
	@make -C libft/
	@mkdir obj
	@gcc $(FLAGS) -c $(3SRC) -I includes
	@mv filler.o obj/
	@mv main.o obj/
	@mv third_algo.o obj/
	@gcc -o $(NAME) $(FLAGS) obj/main.o obj/filler.o obj/third_algo.o  libft/libft.a -I includes
	@echo "\033[32mCreated filler executable\033[0m"

clean:
	@/bin/rm -rf $(OBJ) obj
	@make -C libft/ fclean
	@echo "\033[31mRemoved filler object files\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mRemoved filler executable\033[0m"

re: fclean all
