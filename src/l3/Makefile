CC=gcc
CFLAGS=-I.
DEPS = instruction.h setup.h
OBJ = instruction.o setup.o lc3.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

lc3: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
