CC=gcc
CFLAGS=-I.
#DEPS = *.h
OBJ = test.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
