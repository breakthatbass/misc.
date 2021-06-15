CC=gcc
CFLAGS=-g -fsanitize=address -Wall -Wextra -Weverything -std=c99 -W -pedantic
LIST_FILES=main.c llist.c


list: $(LIST_FILES)
	$(CC) $(LIST_FILES) $(CFLAGS) -o list

clean:
	rm list