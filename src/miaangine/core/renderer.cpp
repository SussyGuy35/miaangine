#include "renderer.hpp"

#include "environment/environment-manager.hpp"

namespace mia 
{
    Renderer::Renderer()
    {

    }
    
    Renderer::~Renderer()   
    {

    }

    bool Renderer::Render(SDL_Renderer* _renderer)
    {
        for (Object* _object : Environment::container->objectList)
        {
            Portrait _portrait = _object->portrait;
            if (_portrait.isEnable)
            {
                SDL_Rect _rect = {
                    (int)(_portrait.position.x + _portrait.offset.x),
                    (int)(_portrait.position.y + _portrait.offset.y),
                    (int)_portrait.size.x,
                    (int)_portrait.size.y
                };
                SDL_SetRenderDrawColor(_renderer, _portrait.color.r, _portrait.color.b, _portrait.color.g, _portrait.color.a);

                SDL_RenderFillRect(_renderer, &_rect);
            }
        }

        SDL_RenderPresent(_renderer);

        return true;
    }
}