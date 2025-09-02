# Flags

CC 		   = gcc
CFLAGS	   = -Isrc -Werror						# include src/ as include search path, warn as error
LDFLAGS    = -Llib -lutils				 		# include lib/ as link search path, add libutils

# Sources

SOL_SRCS  := $(wildcard src/solutions/*/*.c)	# match all .c in solutions
SOL_LIBS  := $(SOL_SRCS:.c=.so)					# replace all .c above to .so and match solutions target
UTIL_SRCS := $(wildcard src/utils/*.c)			# match all .c utils
UTIL_LIB  := lib/libutils.a						# static lib path
UTIL_LIBS := $(UTIL_SRCS:.c=.o)					# replace all .c to .o

# Scripts

main: bin/aoc libs sols

test: bin/test

libs: $(UTIL_LIBS) $(UTIL_LIB)

sols: $(SOL_LIBS)

# Macros

bin/aoc: src/main.c $(UTIL_LIB)
	$(CC) -o $@ $< $(CFLAGS) -ldl

bin/test: src/test.c $(UTIL_LIB)
	$(CC) -o $@ $< $(LDFLAGS) $(CFLAGS)

$(UTIL_LIB): $(UTIL_LIBS)
	ar -rcs $@ $^

src/utils/%.o: src/utils/%.c
	$(CC) -c -fPIC -o $@ $< $(CFLAGS)

src/solutions/%.so: src/solutions/%.c $(UTIL_LIB)
	$(CC) -shared -fPIC -o $@ $< $(CFLAGS) $(LDFLAGS)

clean:
	rm -f bin/* lib/* $(SOL_LIBS) $(UTIL_LIBS)

clean-libs:
	rm -f lib/* $(UTIL_LIBS)

clean-sols:
	rm -f $(SOL_LIBS)
