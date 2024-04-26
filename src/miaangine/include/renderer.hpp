#ifndef _MIA_RENDERER_HPP
#define _MIA_RENDERER_HPP

#include "common.hpp"

#include "portrait.hpp"
#include "image.hpp"
#include "text.hpp"
#include "tilemap.hpp"

namespace mia
{
    class Renderer : public Singleton<Renderer>
    {
    private:
        friend class Singleton<Renderer>;
        Renderer();
        ~Renderer();

    private:
        std::vector<Portrait*> _portraitsList;
        std::vector<Image*> _imagesList;
        std::vector<Text*> _textsList;
        std::vector<Tilemap*> _tilemapsList;
        std::vector<std::pair<rect, SDL_Color>> _debugRectList;

        TTF_Font* _font;

        bool _renderBodies;

    public:
        void SetFont(const char *dir, int size);

        void RegisterPortrait(Portrait *portrait);
        void UnregisterPortrait(Portrait *portrait);

        void RegisterImage(Image *image);
        void UnregisterImage(Image *image);

        void RegisterText(Text *text);
        void UnregisterText(Text *text);

        void RegisterTilemap(Tilemap *tilemap);
        void UnregisterTilemap(Tilemap *tilemap);

        void Render(SDL_Renderer *renderer);

        const std::vector<Portrait*> GetPortraitList();

        void RenderBodiesCollision(bool state);

    private:
        void RenderPortraits(SDL_Renderer *renderer);
        void RenderImages(SDL_Renderer *renderer);
        void RenderTexts(SDL_Renderer *renderer);
        void RenderTilemaps(SDL_Renderer *renderer);
        void RenderBodyRects(SDL_Renderer *renderer);
        
        SDL_Rect WorldRectToSDLScreenRect(const rect& worldRect);
    };
}

#endif