CC=gcc
CFLAGS=-Wall -Werror -pedantic
LDFLAGS=

main: main.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o core