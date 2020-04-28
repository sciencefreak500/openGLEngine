#include "texture.h"

#include <SDL2/SDL_image.h>


Texture::Texture(/* args */)
{
}

Texture::~Texture()
{
}

bool Texture::addSurfaceToList(char * filename)
{
    std::map<char*, SDL_Surface*>::iterator location;
    surfaceDict.find(filename);
    if(location != surfaceDict.end()) {
        return true;
    } else {
        SDL_Surface * surface = IMG_Load(filename);
        surfaceDict.insert(std::pair<char*, SDL_Surface*>(filename, surface));
    }
    return true;
}

GLuint Texture::loadTexture()
{
    GLuint texID = 0;
    SDL_Surface* surface = IMG_Load("../Resources/brick.jpg");
    
    // generate openGL texture and bind the object
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_2D, texID);

    int mode = GL_RGB;
 
    if(surface->format->BytesPerPixel == 4) {
        mode = GL_RGBA;
    }
    
    glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return texID;
}