IDIR = ../include

CC=gcc
CFLAGS=-I$(IDIR) $(shell sdl2-config --cflags) -Wall -Werror -Wpedantic -g -O2

ODIR = ../target

LIBS = $(shell sdl2-config --libs) -lSDL2_image -lm -lSDL2_ttf -lSDL2_mixer

_DEPS = vector.h list.h actor.h sprite.h game.h director.h render.h main.h input.h sound.h
DEPS = $(patsubst %, $(IDIR)/%,$(_DEPS))

_OBJ = vector.o list.o actor.o sprite.o game.o director.o render.o main.o input.o sound.o
OBJ = $(patsubst %, $(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

$(ODIR)/main: $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS) $(LIBS)

