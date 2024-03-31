#include "renderer.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Renderer::Renderer()
    {}

    Renderer::~Renderer()
    {}
#pragma endregion

#pragma region Public method
    void Renderer::RegisterPortrait(Portrait *portrait)
    {
        _portraits.push_back(portrait);
    }

    void Renderer::RemovePortrait(Portrait *portrait)
    {
        auto listenerIterator = std::find(_portraits.begin(), _portraits.end(), portrait);

        if (listenerIterator != _portraits.end())
        {
            _portraits.erase(listenerIterator);
        }
    }

    void Renderer::Render(SDL_Renderer *renderer)
    {
        RenderPortraits(renderer);
    }
#pragma endregion

#pragma region Private method
    void Renderer::RenderPortraits(SDL_Renderer *renderer)
    {
        for (Portrait *portrait : _portraits)
        {
            Sprite *sprite = portrait->sprite();
            mia::v2f position = portrait->master()->GetScreenPosition();

            // TODO
        }
    }
#pragma endregion
}