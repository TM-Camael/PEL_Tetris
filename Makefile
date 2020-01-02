EXE 	= tetris
OBJS	= interface.o tetris.o
CPP	= g++ -fmax-errors=4
UNAME	= $(shell uname)

ifeq ($(UNAME), Linux)
	SDL_INC = `sdl2-config --cflags`
	SDL_LIB = `sdl2-config --libs` -lSDL2_ttf
else
	SDL_LIB	= -framework SDL2 -framework SDL2_ttf
endif

all : $(EXE)

tetris.o: tetris.cpp tetris.h
	$(CPP) $< -c -o $@

interface.o: interface.cpp interface.h
	$(CPP) $< $(SDL_INC) -c -o $@

$(EXE): $(OBJS) main.cpp
	$(CPP) $^ $(SDL_LIB) -o $@

clean:
	-$(RM) $(OBJS) $(EXE)
