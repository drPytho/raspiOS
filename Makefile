# Set compiler to g++
CXX = g++

# Set comilation flags to include SDL
CPPFLAGS = -std=c++11 -Wall -Werror $(shell sdl2-config --cflags) -lawesomium-1-7

# Set Load flags to include SDL
LDFLAGS = $(shell sdl2-config --libs)

# load all .cpp files in directory
SOURCES = source/$(wildcard *.cc)

# create object files from source
OBJECTS = $(SOURCES:.cc=.o)

# Set target
EXE = bin/debug

# g++ -Wall -Werror skeletal.cpp $(sdl2-config --cflags --libs) -o skeletal
all: $(EXE)

	$(EXE): $(OBJECTS)
	$(CXX) $(CPPFLAGS) $(OBJECTS) -o $@

	.cpp.o:
	$(CXX) -c $(SOURCES) -o $@ $(LDFLAGS)

clean:
	rm -f $(OBJECTS) $(EXE)



IDIR =../include
GXX=g++
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = hellomake.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = hellomake.o hellofunc.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(GXX) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 