CC = clang
CFLAGS = -Wall -Wextra -pedantic
LIBS = -lraylib


SRC = src/main.c \
	src/game.c \
	src/objects.c \
	src/render.c



snake: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o snake $(LIBS)

run: snake
	./snake

clean:
	rm -f snake
