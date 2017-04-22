IDIR = ../include

CC=gcc
CFLAGS=-I$(IDIR) $(shell sdl2-config --cflags)

ODIR = ../target

LIBS = $(shell sdl2-config --libs) -lSDL2_image

_DEPS = vector.h list.h game.h render.h main.h 
DEPS = $(patsubst %, $(IDIR)/%,$(_DEPS))

_OBJ = vector.o list.o game.o render.o main.o 
OBJ = $(patsubst %, $(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

$(ODIR)/main: $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS) $(LIBS)

