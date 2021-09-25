OUTDIR=build
CFLAGS=-Wall -g -pedantic -Werror -W -Wextra -c
SRC=$(wildcard src/*.c)

# list of object files, placed in the build directory regardless of source path
OBJECTS = $(addprefix $(OUTDIR)/,$(notdir $(SRC:.c=.o)))

all: $(OBJECTS)

$(OUTDIR)/%.o: src/%.c | $(OUTDIR)
	$(CC) -o $@ $^ $(CFLAGS)


# create the output directory
$(OUTDIR):
	mkdir -p $(OUTDIR)

test:
	cd tests && ./runtests

clean:
	rm -rf $(OUTDIR)
