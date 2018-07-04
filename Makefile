FLAGS = -Werror -Wall -Wextra

NAME = dkotlyar.filler 

FILES = 	main.c \
			filler.c

LIBFILES = 	ft_strlen.c \
			ft_strstr.c \
			ft_strchr.c \
			ft_strsub.c \
			ft_strdup.c \
			ft_strdel.c \
			ft_atoi.c \
			ft_strnew.c \
			get_next_line.c 

INC = libft.h filler.h get_next_line.h

LIBSRC = $(addprefix src/libft/, $(LIBFILES))

FIILERSRC = $(addprefix src/, $(FILES))

INCSRC = $(addprefix includes/, $(INC))

.PHONY: re all clean fclean

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(LIBSRC) $(FILLERSRC) -I $(INCSRC) 
	@echo "\033[32mCreated filler executable\033[0m"

clean:
	/bin/rm -f $(NAME)
	@echo "\033[32mRemoved filler executable\033[0m"

fclean: clean

re: fclean all
