NAME = push_swap
CHECKER = checker

SRC = mandatory/error_handling.c mandatory/ft_split.c mandatory/swap.c mandatory/push.c mandatory/reverse_rotate.c mandatory/rotate.c mandatory/sorting.c\
 		mandatory/stack_utils.c mandatory/utils.c mandatory/push_swap.c mandatory/main.c mandatory/utils1.c
SRCB = bonus/error_handling.c bonus/ft_split.c bonus/swap.c bonus/push.c bonus/reverse_rotate.c bonus/rotate.c\
		bonus/stack_utils.c bonus/utils.c bonus/checker.c bonus/get_next_line.c bonus/get_next_line_utils.c bonus/function_utils.c

HEADER = mandatory/push_swap.h
HEADERB = bonus/push_swap_bonus.h
HEADERGET = bonus/get_next_line.h

OBJS = $(SRC:.c=.o)
OBJSB = $(SRCB:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME) logo

bonus: $(CHECKER) logo

PINK=\033[38;5;125m
pink=\033[38;5;205m
RESET=\033[0m

logo:
	@echo "$(PINK)\n ██▓███   █    ██   ██████  ██░ ██   ██████  █     █░ ▄▄▄       ██▓███     "
	@echo "$(pink)▓██░  ██▒ ██  ▓██▒▒██    ▒ ▓██░ ██▒▒██    ▒ ▓█░ █ ░█░▒████▄    ▓██░  ██▒   "
	@echo "$(PINK)▓██░ ██▓▒▓██  ▒██░░ ▓██▄   ▒██▀▀██░░ ▓██▄   ▒█░ █ ░█ ▒██  ▀█▄  ▓██░ ██▓▒   "
	@echo "$(pink)▒██▄█▓▒ ▒▓▓█  ░██░  ▒   ██▒░▓█ ░██   ▒   ██▒░█░ █ ░█ ░██▄▄▄▄██ ▒██▄█▓▒ ▒   "
	@echo "$(PINK)▒██▒ ░  ░▒▒█████▓ ▒██████▒▒░▓█▒░██▓▒██████▒▒░░██▒██▓  ▓█   ▓██▒▒██▒ ░  ░   "
	@echo "$(pink)▒▓▒░ ░  ░░▒▓▒ ▒ ▒ ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒▒ ▒▓▒ ▒ ░░ ▓░▒ ▒   ▒▒   ▓▒█░▒▓▒░ ░  ░   "
	@echo "$(PINK)░▒ ░     ░░▒░ ░ ░ ░ ░▒  ░ ░ ▒ ░▒░ ░░ ░▒  ░ ░  ▒ ░ ░    ▒   ▒▒ ░░▒ ░        "
	@echo "$(pink)░░        ░░░ ░ ░ ░  ░  ░   ░  ░░ ░░  ░  ░    ░   ░    ░   ▒   ░░          "
	@echo "$(PINK)            ░           ░   ░  ░  ░      ░      ░          ░  ░            $(RESET)\n"

$(NAME): $(OBJS)
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

$(CHECKER): $(OBJSB)
	${CC} ${CFLAGS} ${OBJSB} -o ${CHECKER}

mandatory/%.o: mandatory/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c $(HEADERB) $(HEADERGET)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
	$(RM) $(NAME) $(CHECKER)
	
re: fclean all
