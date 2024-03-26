#ifndef _MIA_TILEMAP_RENDERER_HPP
#define _MIA_TILEMAP_RENDERER_HPP

#include "util/singleton.hpp"

#include <vector>
#include "util/math.hpp"
#include "tilemap/tilemap-data.hpp"

namespace mia
{
    struct TilemapHandle
    {
        Vector<int> position;
        TilemapData data;
        bool isRender = false;
    };

    class TilemapRenderer : public Singleton<TilemapRenderer>
    {
    private:
        friend class Singleton<TilemapRenderer>;
        TilemapRenderer();
        ~TilemapRenderer();

    private:
        std::vector<TilemapHandle*> _tilemaps;

    public:
        int AddTilemap(TilemapData& data);
        bool LoadTilemap(int index);

    
    };
}

#endif