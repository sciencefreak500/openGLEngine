#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

// Include GLM
#include <glm/glm.hpp>

class program   
{   
    private:
        GLFWwindow* window;
        GLuint programID;

    public: 
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
};