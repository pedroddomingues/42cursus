CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -rf

SRC_DIR	= src
SRC = utils.c list.c

OBJ_DIR	= obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INCLUDE_DIR = ./include
INCLUDE = minitalk.h

MAIN =

LIBFT =
LIBS =

NAME = server client

TEST = client_test mult_client

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind-out.txt

NORM = norminette.txt

vpath %.c $(SRC_DIR)
vpath %.h $(INCD_DIR)

all:	$(NAME)

$(NAME):	$(OBJ) $(INCD_DIR) $(addsuffix .c, $(addprefix $(SRC_DIR)/, $(NAME)))
	@echo "Compiling " $@
	@$(CC) $(CFLAGS) $(addprefix $(SRC_DIR)/, $@).c $(OBJ) -o $@
	@echo "Done."

$(OBJ_DIR)/%.o:	%.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $(basename $<)..."
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Done."

test: all $(TEST)

$(TEST): $(addsuffix .c, $(addprefix $(SRC_DIR)/, $(TEST)))
	@echo "Compiling " $@
	@$(CC) $(CFLAGS) $(addprefix $(SRC_DIR)/, $@).c $(OBJ) -o $@
	@echo "Done."


run:	all
	@echo "Running server"
	@./$(NAME)

valgrind: all
	@echo "Running with valgrind"
	@$(VALGRIND) ./$(NAME)

norminette: norminette_run norminette_return

norminette_run:
	@echo "Running norminette..."
	@touch $(NORM)
	@norminette | { grep 'Error' || true; } > $(NORM)

norminette_return:
	@if [ -s $(NORM) ]; then \
	echo "Norminette failed" &&\
	cat $(NORM);\
	else \
	echo "Norminette passed";\
	fi
	@rm -f $(NORM)

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) valgrind*

fclean:	clean
	@$(RM) $(NAME) $(TEST)

re:	fclean all

git:
	git add .
	git status
	git commit -m "$m"
