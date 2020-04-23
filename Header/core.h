#ifndef PROGRAM_H
#define PROGRAM_H

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>


class Program   
{   
    private:
        GLFWwindow* window;
        GLuint programID;
        GLuint vertexBuffer;
        GLuint vertexArrayID;

    public:
        // Render a single object stored in an array
        void render(const GLfloat *object);


        // Arguments: GLFWwindow* window, int width (optional), int height (optional), char* title (optional).
        // Return: boolean. true if initialization success, false otherwise. initialized window then putted into GLFWwindow* window
        bool initGLFW(int width = 1920, int height = 1080, const char* title = "A random program");


        // Initialize GLEW
        // Return: boolean, true if initialization success, false otherwise
        bool initGLEW();


        // Clear the screen, other setup steps will be located here later
        void preRender();


        //
        void cleanScene();


        //
        bool loadShaders(const char* vertex_file_path, const char* fragment_file_path);


        // getters and setters
        GLFWwindow* getCurrentWindow();
        GLuint getProgramID();
        GLuint getVertexBuffer();
        GLuint getVertexArrayID();
};

#endif