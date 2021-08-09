CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = gcc
AR = ar rcs
DIR_OBJ = obj
LIBFT = libft/libft.a
NAME = libftprintf.a

SRC_M = ft_printf.c

OBJ_M = $(SRC_M:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_M) compile_libft
	$(AR) $(NAME) $(OBJ_M)

$(OBJ_M): $(SRC_M)
	@echo "Mandatory objects outdated in ft_printf! Compiling again..."
	$(CC) $(CFLAGS) -c $^
	@echo "Mandatory Compilation Complete in ft_printf!"

bonus: $(OBJ_B) compile_libft
	@$(AR) $(NAME) $(OBJ_B)
	@echo "Bonuses Compilation Complete in ft_printf!"

$(OBJ_B): $(SRC_B)
	@echo "Bonus objects outdated in ft_printf! Compiling again..."
	@$(CC) $(CFLAGS) -c $^
	@mv -f $(SOURCE_B:.c=.o) $(DIR_OBJ)

compile_libft:
	@make all -C libft
	@cp $(LIBFT) $(NAME)

clean:
	@echo "Cleaning up object files in ft_printf..."
	@make clean -C ../libft
	$(RM) $(OBJ_M) $(OBJ_B)

fclean: clean
	@$(RM) $(LIBFT)
	@$(RM) $(NAME)
	@echo "Removed $(NAME)"
	@echo "Removed $(LIBFT)"

norminette:
	@echo "\nChecking norm for ft_printf..."
	@norminette -R CheckForbiddenSourceHeader $(SRC_M)
	@make norminette -C libft/

git:
	git add .
	git commit
	git push

re: fclean all
	@echo "Cleaned and Rebuilt Everything for $(NAME)!"

.PHONY: all clean fclean bonus re norminette compile_libft git