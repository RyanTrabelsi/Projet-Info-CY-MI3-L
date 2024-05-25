CC = gcc
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
HEADERS = $(wildcard *.h)

all: exec

%.o : %.c $(HEADERS)
	$(CC) -c $< -o $@

exec: $(OBJ)
	$(CC) $^ -o $@

clean:
	rm exec
	rm *.o

