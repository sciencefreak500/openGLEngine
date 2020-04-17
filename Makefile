DIRS = Source
LIBS = -lglfw3 -lm -lGL -lGLU -ldl -lX11 -lpthread
OUTPUTNAME = game

CPPCOMPILE = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp))

all: $(CPPCOMPILE)
	g++ $(CPPCOMPILE) -w $(LIBS) -o Executable/$(OUTPUTNAME)
