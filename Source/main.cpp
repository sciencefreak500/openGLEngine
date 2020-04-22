#include <stdlib.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(int argc, char const *argv[])
{
	GLFWwindow* window;
	// initialize GLFW
	if(!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	int width = 640;
	int height = 480;
	window = glfwCreateWindow(640, 480, "openGLEngine", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	// get GL version number
	std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

	// initialize GLEW
	glewExperimental = true;
	GLenum glewInitResult = glewInit();
	if(glewInitResult != GLEW_OK) {
		std::cout << "GLEW init error: " << glewGetErrorString(glewInitResult) << std::endl;
	}
	if(!GLEW_VERSION_2_1) {
		std::cout << "OpenGL 2.1 not supported" << std::endl;
		return false;
	}
	std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	if(!GLEW_ARB_vertex_array_object) {
		std::cout << "GLEW_ARB_vertex_array_object not supported!" << std::endl;
	}
	if(!GLEW_APPLE_vertex_array_object) {
		std::cout << "GLEW_APPLE_vertex_array_object not supported!" << std::endl;
	}
	// enable defaults
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glLineWidth(2);

	//main window loop

	while(!glfwWindowShouldClose(window)) {
		glViewport(0, 0, width, height);
		glClearColor(0, 0, 0, 1); // black background
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}