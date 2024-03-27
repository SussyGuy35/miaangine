#ifndef _MIA_TILEMAP_MANAGER_HPP
#define _MIA_TILEMAP_MANAGER_HPP

#include "util/singleton.hpp"

#include <vector>
#include "util/math.hpp"

namespace mia
{
    class TilemapLayout;

    class TilemapManager : public Singleton<TilemapManager>
    {
    private:
        friend class Singleton<TilemapManager>;
        TilemapManager();
        ~TilemapManager();

    private:
        std::vector<TilemapLayout> _tilemapList;

    public:
        int AddTilemap(TilemapLayout* data);
        void RemoveTilemap(TilemapLayout* data);

        bool Load(int index, Vector2<int> position = Vector2<int>::zero());
        bool Load(int index, int x, int y);
    };
}

#endif