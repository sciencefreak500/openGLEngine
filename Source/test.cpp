#include <GLFW/glfw3.h>
#include <iostream>

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(int argc, char const *argv[])
{
    std::cout << "starting" << std::endl;
    if (!glfwInit())
    {
        // Initialization failed
        std::cout << "failed" << std::endl;
    }
    
    GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
    if (!window)
    {
        std::cout << "window didnt spawn" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    while (!glfwWindowShouldClose(window))
    {
        // Keep running
    }

    glfwDestroyWindow(window);
    return 0;
}
