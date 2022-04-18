CC			=	gcc
FILES 		= 	ft_bzero.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_strchr_i.c \
				ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_pow.c \
				ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
				ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
				ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
				ft_tolower.c ft_calloc.c ft_strdup.c ft_strnstr.c ft_isspace.c \
				ft_substr.c ft_putnbr_base_fd.c ft_itoa.c ft_strrev.c ft_strappend.c \
				ft_strjoin.c ft_strtrim.c ft_strncpy.c ft_putnchar_fd.c ft_strendcmp.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_ullitoa_base.c ft_strcpy.c ft_ftoa.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_split.c get_next_line.c ft_free_split.c \
				ft_strmapi.c ft_number_width.c ft_itoa_base.c ft_printf.c ft_printers.c ft_hexstrtoi.c
FILES_BONUS = 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
				ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS 		=	$(FILES:.c=.o)
OBJS_BONUS 	= $(FILES_BONUS:.c=.o)
FLAGS 		= 	-Wall -Wextra -Werror
NAME 		=	libft.a
RM 			=	rm -f

###################################################################

all:		$(NAME)

$(NAME):	$(OBJS)
				@ar rcs $(NAME) $(OBJS)

%.o:		%.c
				@$(CC) -c $(FLAGS) $<

bonus:		$(OBJS_BONUS)
				@ar rcs $(NAME) $(OBJS_BONUS)

norminette:
	@echo "\nChecking norm for libft..."
	@norminette -R CheckForbiddenSourceHeader $(addprefix $(SRC)/, $(SRC_M))

clean:
				@$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
				@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
