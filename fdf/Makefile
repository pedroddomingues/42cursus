CFLAGS = -g
CC = gcc
FILES = src/*.c ../libft/libft.a
LIBS = -lmlx -lXext -lX11 -lm
EXEC = fdf
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind-out.txt

all:	libft
	@echo "Compiling fdf..."
	@$(CC) $(CFLAGS) $(FILES) $(LIBS) -o $(EXEC)
	@echo "Done."

run:	all
	@echo "Running fdf"
	@./fdf

valgrind: all
	@echo "Running fdf"
	@$(VALGRIND) ./fdf

libft:
	@echo "Compiling libft..."
	@make -R libft
	@echo "libft compiled successfully"
