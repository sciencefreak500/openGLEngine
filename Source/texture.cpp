#include "texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "utils.h"

using namespace util;


Texture::Texture(/* args */)
{
}

Texture::~Texture()
{
}

bool Texture::addSurfaceToList(char * filename)
{
    // std::map<char*, SDL_Surface*>::iterator location;
    // surfaceDict.find(filename);
    // if(location != surfaceDict.end()) {
    //     return true;
    // } else {
    //     SDL_Surface * surface = IMG_Load(filename);
    //     surfaceDict.insert(std::pair<char*, SDL_Surface*>(filename, surface));
    // }
    // return true;
    return true;
}

SDL_Surface * Texture::LoadImage(char* filename)
{
	// Read data
	int32_t width, height, bytesPerPixel;
	void* data = stbi_load(filename, &width, &height, &bytesPerPixel, 0);
	// Calculate pitch
	int pitch;
    pitch = width * bytesPerPixel;
    pitch = (pitch + 3) & ~3;

    // Setup relevance bitmask
	int32_t Rmask, Gmask, Bmask, Amask;
#if SDL_BYTEORDER == SDL_LIL_ENDIAN
    Rmask = 0x000000FF;
    Gmask = 0x0000FF00;
    Bmask = 0x00FF0000;
    Amask = (bytesPerPixel == 4) ? 0xFF000000 : 0;
#else
    int s = (bytesPerPixel == 4) ? 0 : 8;
    Rmask = 0xFF000000 >> s;
    Gmask = 0x00FF0000 >> s;
    Bmask = 0x0000FF00 >> s;
    Amask = 0x000000FF >> s;
#endif
	SDL_Surface* surface = SDL_CreateRGBSurfaceFrom(data, width, height, bytesPerPixel*8, pitch, Rmask, Gmask,
                             Bmask, Amask);
	if (!surface)
	{
		// NOTE: Should free stbi_load 'data' variable here
        print("surface not created!");
		return nullptr;
	}
	return surface;
}

GLuint Texture::loadTexture()
{
    GLuint texID = 0;
    SDL_Surface* surface = LoadImage("../Resources/stone.png");
    if(!surface) {
        print("could not load image!");
        return 0;
    }
    
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