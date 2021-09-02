CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
CC = gcc
AR = ar rcs
DIR_OBJ = obj
M_DIR = mandatory/src
B_DIR = bonus/src
LIBFT = libft/libft.a
NAME = libftprintf.a

SRC_M = ft_printf.c printers.c
SRC_B = ft_printf.c printers.c

OBJ_M = $(addprefix mandatory/$(DIR_OBJ)/, $(SRC_M:.c=.o))
OBJ_B = $(addprefix bonus/$(DIR_OBJ)/, $(SRC_B:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_M) compile_libft
	@$(AR) $(NAME) $(OBJ_M)

$(OBJ_M): $(addprefix $(M_DIR)/, $(SRC_M))
	@mkdir -p $(addprefix mandatory/, $(DIR_OBJ))
	@echo "Mandatory objects outdated in ft_printf! Compiling again..."
	@$(CC) $(CFLAGS) -c $^
	@mv -f $(SRC_M:.c=.o) $(addprefix mandatory/, $(DIR_OBJ))

bonus: $(OBJ_B) compile_libft
	@$(AR) $(NAME) $(OBJ_B)
	@echo "Bonuses Compilation Complete in ft_printf!"

$(OBJ_B): $(addprefix $(B_DIR)/, $(SRC_B))
	@mkdir -p $(addprefix bonus/, $(DIR_OBJ))
	@echo "Bonus objects outdated in ft_printf! Compiling again..."
	@$(CC) $(CFLAGS) -c $^
	@mv -f $(SRC_B:.c=.o) $(addprefix bonus/, $(DIR_OBJ))
	@echo "Bonus Compilation Complete in ft_printf!"

compile_libft:
	@make all -C libft
	@cp $(LIBFT) $(NAME)

clean:
	@echo "Cleaning up object files in ft_printf..."
	@make clean -C libft
	@$(RM) $(OBJ_M) $(OBJ_B) $(DIR_OBJ)

fclean: clean
	@$(RM) $(LIBFT)
	@$(RM) $(NAME)
	@echo "Removed $(NAME)"
	@echo "Removed $(LIBFT)"

norminette:
	@echo "\nChecking norm for ft_printf..."
	@norminette -R CheckForbiddenSourceHeader $(addprefix $(M_DIR)/, $(SRC_M))
	@make norminette -C libft/

git:
	git add .
	git commit
	git push

re: fclean all
	@echo "Cleaned and Rebuilt Everything for $(NAME)!"

.PHONY: all clean fclean bonus re norminette compile_libft git
