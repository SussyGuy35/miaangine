#ifndef _MIA_TILEMAP_DATA_HPP
#define _MIA_TILEMAP_DATA_HPP

#include "tilemap-manager.hpp"

#include <vector>
#include <fstream> 
#include <string>

namespace mia
{
    class TilemapLayout
    {
        friend class TilemapManager;
    
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
        int getWidth() const;
        int getHeight() const;
        int getData(int x, int y) const;
    };

    class TilemapPalette
    {
        friend class TilemapManager;
    
    public:
        TilemapPalette();
        TilemapPalette(const char* paletteDir);

        ~TilemapPalette();

    private:
        // Attributes
        std::vector<std::string> _tileDirs;

    public:
        // Attributes accessing
        const char* getDir(int index) const;
    };
}


#endif