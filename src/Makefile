IDIR = ../include

CC=gcc
CFLAGS=-I$(IDIR) $(shell sdl2-config --cflags) -Wall -Werror -Wpedantic

ODIR = ../target

LIBS = $(shell sdl2-config --libs) -lSDL2_image -lm

_DEPS = vector.h list.h actor.h game.h director.h render.h main.h input.h
DEPS = $(patsubst %, $(IDIR)/%,$(_DEPS))

_OBJ = vector.o list.o actor.o game.o director.o render.o main.o input.o
OBJ = $(patsubst %, $(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

$(ODIR)/main: $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS) $(LIBS)

