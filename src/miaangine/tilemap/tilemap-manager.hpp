#ifndef _MIA_TILEMAP_MANAGER_HPP
#define _MIA_TILEMAP_MANAGER_HPP

#include "util/singleton.hpp"

#include <vector>

#include "tilemap-data.hpp"

namespace mia
{
    class TileMap : public Singleton<TileMap>
    {
    private:
        friend class Singleton<TileMap>;
        TileMap();
        ~TileMap();

    private:
        std::vector<TilemapData> _tilemapList;

    public:
        int AddTilemap(TilemapData* data);
        void RemoveTilemap(TilemapData* data)

        bool Load(int index, Vector<int> position = Vector<int>::zero());
        bool Load(int index, int x, int y);
    };
}

#endif