DIRS = Source
LIBS = -L/usr/local/lib -lglfw3 -lrt -lm -ldl -lX11 -lpthread -lxcb -lXau -lXdmcp -lGLEW -lGLU -lGL -pthread -lX11-xcb -lxcb-glx -ldrm -lXdamage -lXfixes -lxcb-dri2 -lXxf86vm -lXext

OUTPUTNAME = game

CPPCOMPILE = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp))

all: $(CPPCOMPILE)
	g++ $(CPPCOMPILE) -w $(LIBS) -o Executable/$(OUTPUTNAME)
	./Executable/$(OUTPUTNAME)
