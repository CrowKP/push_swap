NAME = libft.a

DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

INCLUDE = -I ../include
CFLAGS = -Wall -Werror -Wextra -MMD
RM = rm -f
FILES  = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_print_hex.c ft_print_nosign.c ft_print_ptr.c ft_printf.c ft_printf_others.c
BFILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJS = $(FILES:.c=.o)
BOBJS = $(BFILES:.c=.o)
DEPS = $(addsuffix .d, $(basename $(FILES)))
BDEPS = $(addsuffix .d, $(basename $(BFILES)))

.c.o:
	@echo "$(BLUE) · $(BROWN)Compiling  ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

all: ${NAME}

-include $(DEPS)
$(NAME): $(OBJS)
		@ar -rcs $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo "\n$(GREEN) Created $(NAME) $(DEF_COLOR)\n"

-include $(BDEPS)
bonus: $(OBJS) $(BOBJS)
		ar -rcs ${NAME} $(OBJS) $(BOBJS)
		ranlib $(NAME)

clean:
		$(RM) $(OBJS) $(DEPS) $(BDEPS)
		$(RM) $(OBJS) $(BOBJS)

fclean: clean
		$(RM) $(NAME)
		$(RM) bonus

re: fclean all

.PHONY: all clean fclean re
