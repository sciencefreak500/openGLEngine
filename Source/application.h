#ifndef APPLICATION_H
#define APPLICATION_H

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
#include "renderer.h"

class Application   
{   
    private:
        GLFWwindow* window;
        Renderer renderer;

    public:
        // constructor
        Application(/* args */);

        // destructor
        ~Application();

        // the main while loop 
        void tick();

        // cleanup and close the application
        void close();

        // Render a single object stored in an array
        void render(const GLfloat object[]);


        // Arguments: GLFWwindow* window, int width (optional), int height (optional), char* title (optional).
        // Return: boolean. true if initialization success, false otherwise. initialized window then putted into GLFWwindow* window
        bool initGLFW(int width = 640, int height = 480, const char* title = "A random program");


        // Initialize GLEW
        // Return: boolean, true if initialization success, false otherwise
        bool initGLEW();

        // Before the main tick loop - setup steps will be located here
        // example: clearing the glBuffer for the next render cycle
        void preTick();


        // cleans the GLEW and GLFW scene
        void cleanScene();


        


        // getters and setters
        GLFWwindow* getCurrentWindow();

};

#endif