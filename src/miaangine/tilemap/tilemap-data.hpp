#ifndef _MIA_TILEMAP_DATA_HPP
#define _MIA_TILEMAP_DATA_HPP

#include "tilemap-manager.hpp"

#include <SDL_image.h>
#include <vector>
#include <fstream> 
#include <string>

namespace mia
{
    class TilemapLayout
    {
    public:
        TilemapLayout();
        TilemapLayout(const char* layoutDir);

        ~TilemapLayout();

    private:
        // Attributes
        int _width, _height;
        int *_data;

    public:
        // Attributes accessing
        int width() const;
        int height() const;
        int getData(int x, int y) const;

        int width(int value);
        int height(int value);
        int setData(int x, int y, int value);
    };

    class TilemapPalette
    {
    public:
        TilemapPalette();
        TilemapPalette(const char* paletteDir);

        ~TilemapPalette();

    private:
        // Attributes
        std::vector<std::string> _tileDirs;
        std::vector<SDL_Texture*> _tileTextures;

    public:
        // Attributes accessing
        const char* getDir(int index) const;

        SDL_Texture* texture(int index);
    };
}


#endif