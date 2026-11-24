NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

COMMON_SRC = utils.c stack.c names.c parse.c rank.c sort.c
SRC = $(COMMON_SRC) medium.c bench.c main.c
BONUS_SRC = $(COMMON_SRC) checker_bonus.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(BONUS): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $@

bonus: $(BONUS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(sort $(OBJ) $(BONUS_OBJ))

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re
