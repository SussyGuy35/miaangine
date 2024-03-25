#ifndef _MIA_TILEMAP_MANAGER_HPP
#define _MIA_TILEMAP_MANAGER_HPP

#include "util/singleton.hpp"

#include "tilemap-data.hpp"

namespace mia
{
    class TileMap : public Singleton<TileMap>
    {
    private:
        friend class Singleton<TileMap>;
        TileMap();
        ~TileMap();


    };
}

#endif