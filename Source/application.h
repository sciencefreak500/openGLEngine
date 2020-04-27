#ifndef APPLICATION_H
#define APPLICATION_H

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include "renderer.h"

class Application   
{   
    private:
        SDL_Window* window;
        Renderer renderer;
        SDL_GLContext glSDLContext;
        bool endApplication = false;
        SDL_Event windowEvent;

    public:
        // constructor
        Application(/* args */);

        // destructor
        ~Application();

        bool init();

        // the main while loop 
        void tick();

        // cleanup and close the application
        void close();

        // Inits a new SDL window with optional width, height, and title args
        bool initSDL(int width = 640, int height = 480, const char* title = "A random program");


        // Initialize GLEW
        // Return: boolean, true if initialization success, false otherwise
        bool initGLEW();

        // Before the main tick loop - setup steps will be located here
        // example: clearing the glBuffer for the next render cycle
        void preTick();

        // Get the keyboard and mouse inputs from the window
        void pollEvents();

};

#endif
