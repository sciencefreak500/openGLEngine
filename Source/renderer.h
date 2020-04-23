#ifndef RENDERER_H
#define RENDERER_H

#include "GL/glew.h"

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Renderer
{
private:
    GLuint programID;
    GLuint attributeCoord2D;

    GLuint vertexbuffer;
    GLuint colorbuffer;

    GLuint VertexArrayID;

    GLuint MatrixID;
    glm::mat4 MVP;

public:
    Renderer();
    ~Renderer();

    void setup();
    // setup work before rendering to the screen - empty for now
    void draw();

    // actually rendering the buffers
    void render();

    void clean();

    // loads in the Shaders from .vs and .fs files
    bool loadShaders(const char* vertex_file_path, const char* fragment_file_path);
};


#endif