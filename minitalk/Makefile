CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -rf

SRC_DIR	= src
SRC = list.c

OBJ_DIR	= obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INCLUDE_DIR = ./include
INCLUDE = minitalk.h
INCLUDE_BONUS = minitalk_bonus.h

# MAIN =

LIBFT = ./libft/libft.a
# LIBS = 

NAME = server client

BONUS = server_bonus client_bonus

TEST = client_test mult_client

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind-out.txt

NORM = norminette.txt

vpath %.c $(SRC_DIR)
vpath %.h $(INCD_DIR)

all:	$(NAME)

$(NAME):	$(OBJ) $(INCD_DIR) $(addsuffix .c, $(addprefix $(SRC_DIR)/, $(NAME))) $(LIBFT)
	@echo "Compiling " $@
	@$(CC) $(CFLAGS) $(addprefix $(SRC_DIR)/, $@).c $(OBJ) $(LIBFT) -o $@
	@echo "Done."

$(OBJ_DIR)/%.o:	%.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $(basename $<)..."
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Done."

bonus:	$(BONUS)

$(BONUS):	$(OBJ) $(INCD_DIR) $(addsuffix .c, $(addprefix $(SRC_DIR)/, $(BONUS))) $(LIBFT)
	@echo "Compiling "$@
	@$(CC) $(CFLAGS) $(addprefix $(SRC_DIR)/, $@).c $(OBJ) $(LIBFT) -o $@
	@echo "Done."

$(LIBFT):
	@echo "Compiling libft..."
	@make -C ./libft
	@echo "libft compiled successfully"

test: all $(TEST)

$(TEST): $(addsuffix .c, $(addprefix $(SRC_DIR)/, $(TEST)))
	@echo "Compiling " $@
	@$(CC) $(CFLAGS) $(addprefix $(SRC_DIR)/, $@).c $(OBJ) $(LIBFT) -o $@
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
	@make clean -C ./libft

fclean:	clean
	@$(RM) $(NAME) $(TEST) $(LIBFT) $(BONUS)


re:	fclean all

git:
	git add .
	git status
	git commit -m "$m"
