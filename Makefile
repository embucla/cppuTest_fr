# -*- MakeFile -*-

#GO: main.c cli.c
#	gcc -o GO main.c cli.c -I -Wall

# -*- MakeFile -*-

CC = gcc
INC = ../inc
CFLAGS=-I$(INC_DIR) -Wall
INC_DIR = inc
SRC_DIR = src

_DEPS = *.h
DEPS = $(patsubst %,$(INC_DIR)/%,$(_DEPS))

_OBJ = *.c
OBJ = $(patsubst %,$(SRC_DIR)/%,$(_OBJ)) main.c


%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

go: $(OBJ)
	gcc $(CFLAGS) -o $@ $^
