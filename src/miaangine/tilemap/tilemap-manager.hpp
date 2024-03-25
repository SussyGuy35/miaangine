#ifndef _MIA_TILEMAP_MANAGER_HPP
#define _MIA_TILEMAP_MANAGER_HPP

#include "util/singleton.hpp"

#include <vector>

namespace mia
{
    class TilemapData;

    class TilemapManager : public Singleton<TilemapManager>
    {
    private:
        friend class Singleton<TilemapManager>;
        TilemapManager();
        ~TilemapManager();

    private:
        std::vector<TilemapData> _tilemapList;

    public:
        int AddTilemap(TilemapData* data);
        void RemoveTilemap(TilemapData* data);

        bool Load(int index, Vector2<int> position = Vector2<int>::zero());
        bool Load(int index, int x, int y);
    };
}

#endif