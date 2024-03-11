#ifndef _MIA_RENDERER_HPP
#define _MID_RENDERER_HPP

#include <memory>

#include "portrait-renderer.hpp"
#include "image-renderer.hpp"

namespace mia
{
    class Renderer
    {
    private:
        static Renderer *__instance;
    public:
        static Renderer* Instance() 
        {
            if (!__instance) __instance = new Renderer(); 
            return __instance;
        }

        Renderer(const Renderer&) = delete;
        void operator=(const Renderer&) = delete;
    
    private:
        Renderer();

    public:
        ~Renderer();
    
    public:
        std::unique_ptr<PortraitRenderer> portraitHandle;
        std::unique_ptr<ImageRenderer> imageHandle;

        void Render(SDL_Renderer *renderer);
    };
}

#endif