IDIR = ../include

CC=gcc
CFLAGS=-I$(IDIR) $(shell sdl2-config --cflags)

ODIR = ../target
SRCDIR = ../src

LIBS = $(shell sdl2-config --libs) -lSDL2_image -lm

_DEPS = vector.h list.h 
DEPS = $(patsubst %, $(IDIR)/%,$(_DEPS))

_OBJ = vector.o list.o tests.o
OBJ = $(patsubst %, $(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

$(ODIR)/test: $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS) $(LIBS)

