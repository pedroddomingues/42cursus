CFLAGS = -g -Wall -Wextra -Werror
CC = gcc
FILES = src/*.c ../libft/libft.a
LIBS = -lmlx -lXext -lX11 -lm
NAME = fdf
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind-out.txt

$(NAME): all

all:	libft
	@echo "Compiling fdf..."
	@$(CC) $(CFLAGS) $(FILES) $(LIBS) -o $(NAME)
	@echo "Done."

run:	all
	@echo "Running fdf"
	@./fdf $(MAP)

valgrind: all
	@echo "Running fdf with Valgrind"
	@$(VALGRIND) ./fdf $(MAP)

libft:
	@echo "Compiling libft..."
	make -R ../libft
	@echo "libft compiled successfully"

norminette:
	@norminette | grep 'Error'
