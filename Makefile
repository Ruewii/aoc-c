CC = gcc
LDFLAGS = -ldl

SOL_SRCS := $(wildcard src/solutions/*/*.c)
SOL_LIBS := $(SOL_SRCS:.c=.so)

all: aoc $(SOL_LIBS)

aoc: src/main.c
	$(CC) -o $@ $< $(LDFLAGS)

src/solutions/%.so: src/solutions/%.c
	$(CC) -shared -o $@ $<

clean:
	rm -f aoc $(SOL_LIBS)
