CC=gcc
CFLAGS=-W -Wall -Werror -Wextra -pedantic -fsanitize=address
SRC_FILES=converter.c helpers.c
NAME=conv

all: $(NAME)

$(NAME): $(SRC_FILES)
	$(CC) -o $(NAME) $(SRC_FILES) $(CFLAGS)

clean:
	rm $(NAME)
