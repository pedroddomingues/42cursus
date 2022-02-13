CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -rf

SRC_DIR	= src
SRC = colors.c errors.c exit.c fdf.c gradients.c hooks.c instructions.c map.c pixels.c points.c

OBJ_DIR	= obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INCLUDE_DIR = ./include
INCLUDE = fdf.h keys.h

MAIN = src/main.c

LIBS = ./libft/libft.a -lmlx -lXext -lX11 -lm

NAME = fdf

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind-out.txt

vpath %.c $(SRC_DIR)
vpath %.h $(INCD_DIR)

all:	$(NAME)

$(NAME):	libft $(OBJ)
	@echo "Compiling fdf..."
	$(CC) $(CFLAGS) $(MAIN) $(OBJ) $(LIBS) -o $(NAME)
	@echo "Done."

$(OBJ_DIR)/%.o:	%.c
	@echo "Compiling $(basename $<)..."
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Done."

run:	all
	@echo "Running fdf"
	@./$(NAME) $(MAP)

valgrind: all
	@echo "Running fdf with Valgrind"
	@$(VALGRIND) ./$(NAME) $(MAP)

libft:
	@echo "Compiling libft..."
	make -R ../libft
	@echo "libft compiled successfully"

norminette:
	@norminette | grep 'Error'

clean:
	@$(RM) $(OBJ_DIR)

fclean:		clean
	@$(RM) $(NAME)

re:	fclean all

git:
	git add .
	git status
	git commit -m "$m"
