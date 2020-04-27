#include "renderer.h"
#include "application.h"
#include "utils.h"

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace util;


Application::Application()
{
}

Application::~Application()
{
}

bool Application::init()
{
    if (!initSDL() || !initGLEW())
    {
        perror("INIT ERROR");
        close();
        return false;
    }
    if(!renderer.loadShaders("Shaders/simple.vs", "Shaders/red.fs")) {
        print("Shaders didnt load!");
        close();
        return false;
    }
    print("Application Initialized");

    renderer.setup();
    
    return true;
}

void Application::tick()
{
    print("tick begin");
    while(!endApplication) {
        preTick();
        renderer.render();
        
        SDL_GL_SwapWindow(window);
        pollEvents();
    }
    close();
}

void Application::close()
{
    renderer.clean();
    SDL_GL_DeleteContext(glSDLContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Application::initSDL(int width, int height, const char *title)
{
    // initialize these subsystems
    SDL_SetMainReady();
    uint32_t subsystemList = SDL_INIT_VIDEO | SDL_INIT_AUDIO;
    SDL_Init(subsystemList);
    // verify if initialization is complete
    if (SDL_WasInit(SDL_INIT_VIDEO) == subsystemList)
    {
        print("SDL Error!");
        print(SDL_GetError());
        getchar();
        return false;
    }

    // add attributes for OpenGL integration with SDL2
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    // Open a window and create its OpenGL context
    window = SDL_CreateWindow(
        title, 
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
        width, height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
    );
    if (window == NULL)
    {
        print("Failed to open SDL window.");
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    // create the GL context
    glSDLContext = SDL_GL_CreateContext(window);


    return true;
}

bool Application::initGLEW()
{
    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "Failed to initialize GLEW\n");
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }
    return true;
}


void Application::preTick()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Application::pollEvents()
{
    if(SDL_PollEvent(&windowEvent)) {
        // any quit event created
        if(windowEvent.type == SDL_QUIT) {
            endApplication = true;
        }
        
        // keydown event
        if(windowEvent.type == SDL_KEYDOWN) {
            SDL_Keycode key =  windowEvent.key.keysym.sym;
            // escape = quit application
            if(key == SDLK_ESCAPE) {
                endApplication = true;
            }
        }
        // keyup event
        if(windowEvent.type == SDL_KEYUP) {
            SDL_Keycode key =  windowEvent.key.keysym.sym;
        }
    }
}
