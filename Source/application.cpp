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
    if (!initGLFW() || !initGLEW())
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
    while(!glfwWindowShouldClose(window)) {
        preTick();
        renderer.render();
        
        glfwSwapBuffers(window);
		glfwPollEvents();
    }
    close();
}

void Application::close()
{
    renderer.clean();
    glfwTerminate();
}

bool Application::initGLFW(int width, int height, const char *title)
{
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        getchar();
        return false;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL)
    {
        fprintf(stderr, "Failed to open GLFW window.\n");
        getchar();
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    return true;
}

bool Application::initGLEW()
{
    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "Failed to initialize GLEW\n");
        glfwTerminate();
        return false;
    }
    return true;
}


void Application::preTick()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
