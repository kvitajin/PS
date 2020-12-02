CC=gcc
CFLAGS=-I.
DEPS = md5.h
OBJ = md5.o  

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cv6: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
