DIRS = Source
LIBS = -L/usr/local/lib -lglfw3 -lrt -lm -ldl -lX11 -lpthread -lxcb -lXau -lXdmcp -lGLEW -lGLU -lGL -pthread -lX11-xcb -lxcb-glx -ldrm -lXdamage -lXfixes -lxcb-dri2 -lXxf86vm -lXext

OUTPUTNAME = game

CPPCOMPILE = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp))

all: $(CPPCOMPILE) core.o
	g++ $(CPPCOMPILE) core.o -w $(LIBS) -o Executable/$(OUTPUTNAME)
	cp -r Source/Shaders Executable
	cd Executable && ./$(OUTPUTNAME)
	rm core.o

core.o:
	g++ -c Source/core/header/core.h Source/core/core.cpp
