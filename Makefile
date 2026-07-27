CC = clang
CFLAGS = -Wall -Wextra -pedantic
LIBS = -lraylib

snake: src/main.c
	$(CC) $(CFLAGS) src/main.c -o snake $(LIBS)

run: snake
	./snake

clean:
	rm -f snake
