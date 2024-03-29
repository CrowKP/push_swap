NAME = push_swap

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

INCLUDE = -I include
RM = rm -f
AR = ar -rcs
CFLAGS = -Wall -Werror -Wextra -MMD
FILES = ./src/main.c ./src/funprint.c ./src/funmove.c ./src/utils.c ./src/index.c \
	./src/errors.c ./src/i5utils.c ./src/i100utils.c ./src/ft_atoi.c ./src/checks.c \
	./src/i4utils.c ./src/orderutils.c ./src/orderutils2.c ./src/i500utils.c
OBJS = $(FILES:.c=.o)
LIB_DIR = lib/
RM_DEPS = *.d
LIB_DIR_DEPS = lib/*.d
LIB_DIR_OBJ = lib/*.o
CC = gcc
DEPS = $(addsuffix .d, $(basename $(FILES)))
HEADER = include/push_swap.h include/libft.h include/ft_printf.h

.c.o:
	@echo "$(BLUE) · $(BROWN)Compiling  ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJS) 
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(FILES) -L lib/ -lft
	@echo "\n$(GREEN) $(NAME) feels nice and ready $(DEF_COLOR)\n"

clean:
	@$(RM) $(OBJS) $(LIB_DIR_OBJ)
	@$(RM) $(DEPS) lib/libft.a
	@$(RM) $(RM_DEPS) $(LIB_DIR_DEPS)
	@echo "\n${BLUE} · $(RED)All objects cleaned successfully ${BLUE}·$(DEF_COLOR)\n"

fclean: clean
	@$(RM) $(NAME)
	@echo "\n${BLUE} · $(RED)All objects and executable cleaned successfully${BLUE} ·$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
