#ifndef _MIA_IMAGE_RENDERER_HPP
#define _MIA_IMAGE_RENDERER_HPP

#include <SDL.h>
#include <SDL_image.h>

#include <vector>

#include "image.hpp"

namespace mia 
{
    class ImageRenderer
    {
    private:
        static ImageRenderer *__instance;
    public:
        static ImageRenderer* Instance() 
        {
            if (!__instance) __instance = new ImageRenderer(); 
            return __instance;
        }

        ImageRenderer(const ImageRenderer&) = delete;
        void operator=(const ImageRenderer&) = delete;
    
    private:
        ImageRenderer();

    public:
        ~ImageRenderer();

    private:
        std::vector<Image*> _images;

    public:
        void RegisterImage(Image *image);
        void RemoveImage(Image *image);

        void Render(SDL_Renderer *renderer);

    private:
        SDL_Rect RectRenderingCalculate(const Image *image);
    };
}

#endif