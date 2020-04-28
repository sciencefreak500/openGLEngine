DIRS = Source
LIBS = -lSDL2 -lGLEW -lGLU -lGL -lSDL2_image

OUTPUTNAME = game

CPPCOMPILE = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp))

all: $(CPPCOMPILE)
	g++ $(CPPCOMPILE) -w $(LIBS) -o Executable/$(OUTPUTNAME)
	cp -r Source/Shaders Executable && echo ""
	cd Executable && ./$(OUTPUTNAME)


debug: $(CPPCOMPILE)
	g++ $(CPPCOMPILE) -w $(LIBS) -o Executable/$(OUTPUTNAME)
	cp -r Source/Shaders Executable && echo ""
	cd Executable && gdb -x ../gdbinit ./$(OUTPUTNAME)
