NAME	= philosophers
CFLAGS	:= -g -Wall -Wextra -Werror
CFILES	= philosophers.c

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

