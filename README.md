# openGLEngine
Just a game engine from scratch using openGL, just learning some stuff.
I'll add to this periodically when I need to scratch my game dev itch

### To Build
install the dependancies in `Dependancies` Some will need installing using `apt-get`
GLFW needs to be build from source. remove `build`, folder, then:
```
cd <root_glfw3>
mkdir build
cd build
cmake ..
make
sudo make install
```
That should install glfw on your system.

### To Run
in the root directory just run `make`. If it all runs fine, the executable `game` is found in `Executables` 
just run that file to see the game.
