#ifndef APPLICATION_H
#define APPLICATION_H

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include "renderer.h"
#include "event-handler.h"

class Application : public EventHandler
{   
    private:
        Renderer renderer;
        SDL_GLContext glSDLContext;

        bool endApplication = false;
        int lastTime;

    protected:
        float deltaTime;

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

        // Before the render function is called, starts the tick loop off
        void preTick();

        // after render function is called, ends the tick loop
        void postTick();

        // Get the keyboard and mouse inputs from the window
        void pollEvents();

        //helper functions
        float getTimeDelta();

};

#endif
