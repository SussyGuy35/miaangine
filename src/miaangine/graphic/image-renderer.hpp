#ifndef _MIA_IMAGE_RENDERER_HPP
#define _MIA_IMAGE_RENDERER_HPP

#include <SDL.h>
#include <SDL_image.h>

#include <vector>

#include "util/singleton.hpp"

#include "image.hpp"

namespace mia 
{
    class ImageRenderer : public Singleton<ImageRenderer>
    {
    private:
        friend class Singleton<ImageRenderer>;
        ImageRenderer();
        ~ImageRenderer();

    private:
        std::vector<Image*> _images;

    public:
        void RegisterImage(Image *image);
        void RemoveImage(Image *image);

        void Render(SDL_Renderer *renderer);

    private:
        SDL_Rect RectRenderingCalculate(Image *image);
    };
}

#endif