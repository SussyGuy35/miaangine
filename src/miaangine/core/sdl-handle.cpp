#include "sdl-handle.hpp"

#include "engine-components.hpp"

namespace mia
{
    SDLHandle::SDLHandle()
    {}

    SDLHandle::~SDLHandle()
    {}

    bool SDLHandle::Init(uint32_t width, uint32_t height, bool fullscreen)
    {
        if(SDL_Init(SDL_INIT_VIDEO) < 0) return false;

        window = SDL_CreateWindow( 
            "MIAANGINE", 
            SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, 
            width,
            height,
            SDL_WINDOW_OPENGL
        );
        if (window == nullptr) return false;

        renderer = SDL_CreateRenderer(
            window, 
            -1, 
            SDL_RENDERER_ACCELERATED
        );
        if (renderer == nullptr) return false;

        int imgFlags = IMG_INIT_PNG;
        if ((IMG_Init(imgFlags) & imgFlags) != imgFlags) return false;

        return true;
    }

    void SDLHandle::Clear()
    {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        IMG_Quit();
    }

    SDL_Texture* SDLHandle::LoadIMG(const char* file)
    {
        string dir;
        dir.copy(assetDir);
        dir += file;

        debug.Log("Image load: %s", dir.str());
        return IMG_LoadTexture(sdl.renderer, dir.str());
    }

    void SDLHandle::SetAssetDir(const char* directory)
    {
        assetDir = directory;
        if (directory[strlen(directory) - 1] != '/')
        {
            assetDir += "/";
        }
    }
}