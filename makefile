# A simple Makefile for compiling small SDL projects

# set the compiler
CC := g++

# set the compiler flags
CFLAGS := `sdl2-config --libs --cflags`  --std=c++14 -Wall -lSDL2_image

HDRS := includes.h game.h
SRCS := game.cpp oninit.cpp loadcontent.cpp onevent.cpp onloop.cpp onrender.cpp

EXEC := game.out

# default recipe
all: $(HDRS) $(SRCS)
	$(CC) -o $(EXEC) $(SRCS) $(CFLAGS) 

# recipe for building the final executable
$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

# recipe for building object files
$(OBJS): $(@:.o=.c) $(HDRS) Makefile
	$(CC) -o $@ $(@:.o=.c) -c $(CFLAGS)


# recipe to clean the workspace
clean:
	rm -f *.o $(EXEC)

