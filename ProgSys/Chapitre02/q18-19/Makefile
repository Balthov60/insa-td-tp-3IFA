CC=gcc
CFLAGS=-Wall -Werror 
LDFLAGS=

main: main.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o core