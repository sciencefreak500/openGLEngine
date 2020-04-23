#ifndef RENDERER_H
#define RENDERER_H

// Include GLEW
#include <GL/glew.h>

class Renderer
{
private:
    GLuint program;
    GLuint attributeCoord2D;
    // GLuint vertexBuffer;
    // GLuint vertexArrayID;
public:
    Renderer();
    ~Renderer();

    // setup work before rendering to the screen - empty for now
    void draw();

    // actually rendering the buffers
    void render();

    // loads in the Shaders from .vs and .fs files
    bool loadShaders(const char* vertex_file_path, const char* fragment_file_path);
};


#endif