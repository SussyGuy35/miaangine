#ifndef _MIA_TILEMAP_MANAGER_HPP
#define _MIA_TILEMAP_MANAGER_HPP

#include "util/singleton.hpp"

#include <vector>
#include <utility>
#include "util/math.hpp"

#include "tilemap-data.hpp"

namespace mia
{
    class TilemapManager : public Singleton<TilemapManager>
    {
    private:
        friend class Singleton<TilemapManager>;
        TilemapManager();
        ~TilemapManager();

    private:
        std::vector<std::pair<TilemapLayout*, TilemapPalette*>> _tilemapList;

    public:
        int AddTilemap(TilemapLayout *layout, TilemapPalette *palette);
        // void RemoveTilemap(TilemapLayout* data); //TODO

        bool Load(int index, Vector2<> position = Vector2<>::zero(), Vector2<> size = Vector2<>::one());
        bool Load(int index, float px, float py, float sx = 1, float sy = 1);
    };
}

#endif