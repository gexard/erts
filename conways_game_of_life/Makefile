CC = gcc
CFLAGS = -Wall -I/usr/include/ -I.
LDFLAGS = -lncurses
DEPS = conway.h
OBJ = main.o mechanics.o structures.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

conway: $(OBJ)
	$(CC)  -o $@ $^  $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ) conway
