# Flags

CC 		   = gcc
CFLAGS	   = -fPIC -Isrc -Werror
LDFLAGS    = -Llib -lutils -Wl,-rpath=./lib -ldl

# Sources

SOL_SRCS  := $(wildcard src/solutions/*/*.c)	# match all .c in solutions
SOL_LIBS  := $(SOL_SRCS:.c=.so) 				# replace all .c above to .so and match solutions target
UTIL_SRCS := $(wildcard src/utils/*.c)			# match all .c utils

# Shared objects

UTIL_LIB  := lib/libutils.so

# Scripts

all: aoc $(UTIL_LIB) $(SOL_LIBS)

aoc: src/main.c $(UTIL_LIB)
	$(CC) -o $@ $< -Llib -lutils $(LDFLAGS)

$(UTIL_LIB): $(UTIL_SRCS)
	$(CC) -shared -o $@ $? $(CFLAGS)

src/solutions/%.so: src/solutions/%.c $(UTIL_LIB)
	$(CC) -shared -o $@ $< -Llib -lutils $(CFLAGS)

test: src/test.c $(UTIL_LIB)
	$(CC) -o $@ $< -Llib -lutils $(CFLAGS) $(LDFLAGS)

clean:
	rm -f aoc $(SOL_LIBS) $(UTIL_LIB)
