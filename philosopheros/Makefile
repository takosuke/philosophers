NAME	= philosophers
CFLAGS	:= -g -Wall -Wextra -Werror
CFILES	= utils.c init.c main.c threads.c

.PHONY: all
all: $(NAME) 

$(NAME): $(CFILES)
	cc $(CFLAGS) $(CFILES) -o $(NAME)

.PHONY: clean
clean: 
	rm -f $(NAME)

.PHONY: fclean
fclean: 
	rm -f $(NAME)

.PHONY: re
re: fclean all

