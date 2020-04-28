#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string.h>
#include <map>


class Texture
{
private:
    std::map< char*, SDL_Surface* > surfaceDict;
public:
    Texture();
    ~Texture();

    // add a surface to an array if not loaded in yet
    bool addSurfaceToList(char * filename);

    // load texture
    GLuint loadTexture();

    // load image to SDL_Surface
    SDL_Surface *LoadImage(char* filename);
};



#endif