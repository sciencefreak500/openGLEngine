#ifndef RENDERER_H
#define RENDERER_H

#include "GL/glew.h"
#include "texture.h"

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Renderer
{
private:
    // shader program id
    GLuint programID;
    
    // buffer data that gets refreshed every tick
    GLuint vertexbuffer;
    GLuint colorbuffer;

    // positioning of buffer data in array format
    GLuint VertexArrayID;

    // matrix projections for camera perspective
    GLuint MatrixID;
    glm::mat4 MVP;

    // texture 
    GLuint texture;
    GLuint textureID;

public:
    // constructor
    Renderer();

    // destructor
    ~Renderer();

    // initial configs for VBO and defaults for GLEW, happens once
    void setup();

    // setup work before rendering to the screen - empty for now
    void draw();

    // actually rendering the buffers, looping
    void render();

    // after game ends, clean the buffers out.
    void clean();

    // loads in the Shaders from .vs and .fs files
    bool loadShaders(const char* vertex_file_path, const char* fragment_file_path);
};


#endif