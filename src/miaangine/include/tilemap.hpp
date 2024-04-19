#ifndef _MIA_TILEMAP_HPP
#define _MIA_TILEMAP_HPP

#include "common.hpp"

#include "tilemap-palette.hpp"

namespace mia
{
    class Tilemap
    {
    public:
        Tilemap(const char *dir, TilemapPalette *palette, v2f size, v2f position = v2f::zero());
        virtual ~Tilemap();

    private:
        int *_layout;
        TilemapPalette *_palette;

        int _width;
        int _height;

        v2f _position;
        v2f _size;

        std::vector<rect> _exposedRects;

    public:
        int width() const;
        int height() const;
        const TilemapPalette& palette() const;
        const v2f& position() const;
        const v2f& size() const;

        int* layout();
        TilemapPalette& palette();
        int& width();
        int& height();
        v2f& position();
        v2f& size();

        bool LoadLayout(const char *dir);
        void UpdateLayout();
        void SetPalette(TilemapPalette *palette);

        bool HasTile(int x, int y);
        Sprite& GetSprite(int x, int y);
        rect GetSpriteRect(int x, int y);
        rect GetRect(int x, int y);

        std::vector<rect>& GetAllExposedRects();

    private:
        bool CheckExposed(int x, int y);
    };
}

#endif