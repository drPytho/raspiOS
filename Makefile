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












SHELL = /bin/sh
CC    = g++
 
FLAGS        = -std=c++11 
CFLAGS       = -Werror -Wall -Wextra
DEBUGFLAGS   = -O0 -D _DEBUG
RELEASEFLAGS = -O2 -D NDEBUG -combine -fwhole-program
 
TARGET  = foomatic-widget
SOURCES = $(shell echo src/*.c)
COMMON  = include/definitions.h include/debug.h
HEADERS = $(shell echo include/*.h)
OBJECTS = $(SOURCES:.c=.o)
 
PREFIX = $(DESTDIR)/usr/local
BINDIR = $(PREFIX)/bin
 
 
all: $(TARGET)
 
$(TARGET): $(OBJECTS) $(COMMON)
  $(CC) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) -o $(TARGET) $(OBJECTS)

release: $(SOURCES) $(HEADERS) $(COMMON)
  $(CC) $(FLAGS) $(CFLAGS) $(RELEASEFLAGS) -o $(TARGET) $(SOURCES)

profile: CFLAGS += -pg
profile: $(TARGET)
 
 
install: release
  install -D $(TARGET) $(BINDIR)/$(TARGET)
 
install-strip: release
  install -D -s $(TARGET) $(BINDIR)/$(TARGET)
 
uninstall:
  -rm $(BINDIR)/$(TARGET)
 
 
clean:
  -rm -f $(OBJECTS)
  -rm -f gmon.out
 
distclean: clean
  -rm -f $(TARGET)
 
 
.SECONDEXPANSION:
 
$(foreach OBJ,$(OBJECTS),$(eval $(OBJ)_DEPS = $(shell gcc -MM $(OBJ:.o=.c) | sed s/.*://)))
%.o: %.c $$($$@_DEPS)
  $(CC) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) -c -o $@ $<
 
# %.o: %.c $(HEADERS) $(COMMON)
#    $(CC) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) -c -o $@ $<
 
 








